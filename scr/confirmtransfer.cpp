#include "confirmtransfer.h"
#include "ui_confirmtransfer.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

#include <bits/stdc++.h>
#include <ctime>

using namespace std;

ConfirmTransfer::ConfirmTransfer(User originUser, int originBankAccountIdx, QString destiCardNumber, long long int amount, QWidget *parent) : QWidget(parent) , ui(new Ui::ConfirmTransfer) {
    ui->setupUi(this);

    //disable maximize
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    initialUsersSet(originUser, originBankAccountIdx, destiCardNumber, amount);
    addInfo();

    hideError();

    //set password label
    if (originCard.getHaveFixedPassword() && amount <= 100000) {
        ui->passwordL->setText("Fixed Password :");
    }
    else if (!originCard.getHaveFixedPassword() || amount > 100000) {
        ui->passwordL->setText("One Time Password :");
    }

    //click to open pages
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));

    //click password request push button
    connect(ui->PasswordReqPB, SIGNAL(clicked()), this, SLOT(passwordReqPBClick()));

    //click confirm push button
    connect(ui->confirmPB, SIGNAL(clicked()), this, SLOT(confirmTransferPBClick()));

    //click cancel push button
    connect(ui->cancelPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));

    //click enter for request password
    connect(ui->cvv2LE, SIGNAL(returnPressed()), ui->PasswordReqPB, SLOT(click()));

    //click enter for confirm
    connect(ui->passwordLE, SIGNAL(returnPressed()), ui->confirmPB, SLOT(click()));

    //set cursor
    ui->cvv2LE->setFocus();
}
ConfirmTransfer::~ConfirmTransfer() {
    delete ui;
}

void ConfirmTransfer::initialUsersSet(User originUser, int originBankAccountIdx, QString destiCardNumber, long long int amount) {
    this->originBankAccountIdx = originBankAccountIdx;
    this->originUser = originUser;
    this->originBankAccount = originUser.getSingleBankAccount(originBankAccountIdx);
    this->originCard = originUser.getSingleBankAccount(originBankAccountIdx).getBankCard();

    this->destiBankAccountIdx = originUser.findDestiUserIdx(destiCardNumber);
    this->destiUser = originUser.findDestiUser(destiCardNumber);
    this->destiBankAccount = destiUser.getSingleBankAccount(destiBankAccountIdx);
    this->destiCard = destiUser.getSingleBankAccount(destiBankAccountIdx).getBankCard();

    this->amount = amount;
}

void ConfirmTransfer::addInfo() {
    ui->firstNameST->setText(originUser.getName());
    ui->lastNameST->setText(originUser.getFamily());
    ui->nationalCodeST->setText(originUser.getNationalCode());
    ui->ageST->setText(QString::number(originUser.getAge()));
    ui->nameST->setText(destiUser.getName() + "  " + destiUser.getFamily());
    ui->amountLE->setText(QString::number(amount) + " T");
}

void ConfirmTransfer::hideError() {
    ui->cvv2Error->hide();
    ui->passwordError->hide();
}

void ConfirmTransfer::confirmTransferPBClick() {
    hideError();

    bool checkError = true;

    //for not changing checkError from false to true
    if (checkCvv2Field())
        checkError = false;
    if (checkFixedPasswordField())
        checkError = false;
    if (checkOneTimePasswordField())
        checkError = false;

    if (checkError) {
        finalUsersSet();
        openMainPanelPage();
    }
}

bool ConfirmTransfer::checkCvv2Field() {
    if (ui->cvv2LE->text() == "") {
        ui->cvv2Error->setText("This field is empty");
        ui->cvv2Error->show();
        return true;
    }
    else if (checkNumber(ui->cvv2LE->text())) {
        ui->cvv2Error->setText("This field is invalid");
        ui->cvv2Error->show();
        return true;
    }
    else if (checkCvv2(ui->cvv2LE->text())) {
        ui->cvv2Error->setText("This field is incorrect");
        ui->cvv2Error->show();
        return true;
    }
    return false;
}

bool ConfirmTransfer::checkFixedPasswordField() {
    if (originCard.getHaveFixedPassword() && amount <= 100000) {
        if (ui->passwordLE->text() == "") {
            ui->passwordError->setText("This field is empty");
            ui->passwordError->show();
            return true;
        }
        else if (checkNumber(ui->passwordLE->text())) {
            ui->passwordError->setText("This field is invalid");
            ui->passwordError->show();
            return true;
        }
        else if (checkFixedPassword(ui->passwordLE->text())) {
            ui->passwordError->setText("This field is incorrect");
            ui->passwordError->show();
            return true;
        }
    }
    return false;
}

bool ConfirmTransfer::checkOneTimePasswordField() {
    if (!originCard.getHaveFixedPassword() || amount > 100000) {
        if (ui->passwordLE->text() == "") {
            ui->passwordError->setText("This field is empty");
            ui->passwordError->show();
            return true;
        }
        else if (checkNumber(ui->passwordLE->text())) {
            ui->passwordError->setText("This field is invalid");
            ui->passwordError->show();
            return true;
        }
        else if (checkOneTimePassword(ui->passwordLE->text())) {
            ui->passwordError->setText("This field is incorrect");
            ui->passwordError->show();
            return true;
        }
    }
    return false;
}

bool ConfirmTransfer::checkNumber(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] < '0') || (text[i] > '9')) {
            return true;
        }
    }
    return false;
}

bool ConfirmTransfer::checkCvv2(QString cvv2) {
    if (cvv2.size() == 4) {
        if (originCard.getCvv2() == cvv2)
            return false;
    }
    return true;
}

bool ConfirmTransfer::checkFixedPassword(QString fixedPassword) {
    if (fixedPassword.size() >= 4 && fixedPassword.size() <= 12) {
        if (originCard.getFixedPassword() == fixedPassword)
            return false;
    }
    return true;
}

bool ConfirmTransfer::checkOneTimePassword(QString oneTimePassword) {
    if (oneTimePassword.size() == 6) {
        if (originCard.getOneTimePassword() == oneTimePassword)
            return false;
    }
    return true;
}

void ConfirmTransfer::passwordReqPBClick() {
    if (ui->passwordL->text() == "One Time Password :") {
        srand(time(0));

        string password = originUser.getNationalCode().toStdString();
        random_shuffle(password.begin(), password.end());

        for (int i = 0; i < 4; i++)
            password.pop_back();

        originCard.setOneTimePassword(QString::fromStdString(password));
        ui->passwordLE->setText(QString::fromStdString(password));
        ui->PasswordReqPB->setDisabled(true);
    }
    else {
        ui->passwordError->setText("You can't use one time password");
        ui->passwordError->show();
    }
}

void ConfirmTransfer::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(originUser);
    np->show();
    this->close();
}

void ConfirmTransfer::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(originUser);
    np->show();
    this->close();
}

void ConfirmTransfer::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(originUser);
    np->show();
    this->close();
}

void ConfirmTransfer::openTransferPage() {
    Transfer *np = new Transfer(originUser);
    np->show();
    this->close();
}

void ConfirmTransfer::openMainPanelPage() {
    MainPanel *np = new MainPanel(originUser);
    np->show();
    this->close();
}

void ConfirmTransfer::openLogoutPage() {
    LoginSignin *np = new LoginSignin(originUser);
    np->show();
    this->close();
}

tm ConfirmTransfer::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    return *std::localtime(&now);
}

void ConfirmTransfer::finalUsersSet() {
    //set origin bank account
    originBankAccount.setBalance(originBankAccount.getBalance() - amount - (amount * 0.0001));

    //set last transfer information
    tm last24HourDate = calculatePastDate(24);
    if (!isAfter(originBankAccount.getLastTransferDate(), last24HourDate)) {
        originBankAccount.setLastTransferDate(getCurrentTime());
        originBankAccount.setLastTransferAmount(0);
    }
    originBankAccount.setLastTransferAmount(originBankAccount.getLastTransferAmount() + amount);

    originUser.setSingleBankAccount(originBankAccount, originBankAccountIdx);

    //set destination bank account
    destiBankAccount.setBalance(destiBankAccount.getBalance() + amount);

    if (originUser.getNationalCode() == destiUser.getNationalCode()) {
        //set destination user to origin user
        originUser.setSingleBankAccount(destiBankAccount, destiBankAccountIdx);
    }
    else {
        //set destination user
        destiUser.setSingleBankAccount(destiBankAccount, destiBankAccountIdx);

        //set to list of users
        destiUser.updateUserDataInList(destiUser.getNationalCode());
    }

    //set to list of users
    originUser.updateUserDataInList(originUser.getNationalCode());
}

bool ConfirmTransfer::isAfter(const tm& time12, const tm& time22) {
    time_t time11 = mktime(const_cast<tm*>(&time12));
    time_t time21 = mktime(const_cast<tm*>(&time22));
    return time21 < time11;
}

tm ConfirmTransfer::calculatePastDate(int hours) {
    tm currentDate = getCurrentTime();
    currentDate.tm_hour -= hours;
    mktime(&currentDate);
    return currentDate;
}
