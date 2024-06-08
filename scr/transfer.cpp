#include "transfer.h"
#include "ui_transfer.h"
#include "user.h"
#include "loginsignin.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "confirmtransfer.h"

#include <ctime>

using namespace std;

Transfer::Transfer(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::Transfer) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    hideError();

    //click to open pages
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));

    //click continue push button
    connect(ui->continuePB, SIGNAL(clicked()), this, SLOT(checkTransfer()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
Transfer::~Transfer() {
    delete ui;
}

void Transfer::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));

    //origin card number combo box
    for (int i = 0; i < users.getBankAccountNum(); i++) {
        ui->originCardNumberCB->addItem(users.getSingleBankAccount(i).getBankCard().getCardNumber());
    }
}

void Transfer::continuePBClick() {
    setUserTransferData();

    ConfirmTransfer *np = new ConfirmTransfer(users, bankAccountIdx, ui->destiCardNumberLE->text(), ui->amountLE->text().toLongLong());
    np->show();
    this->close();
}

void Transfer::hideError() {
    ui->originCardNumberError->hide();
    ui->destiCardNmuberError->hide();
    ui->amountError->hide();
}

void Transfer::checkTransfer() {
    hideError();

    bool checkError = true;

    //set user bank account idx
    setIdx();

    //set bank account and card to this
    this->bankAccounts = users.getSingleBankAccount(bankAccountIdx);
    this->cards = users.getSingleBankAccount(bankAccountIdx).getBankCard();

    //for not changing checkError from false to true
    if (checkSameCardNumbers())
        checkError = false;
    if (checkOriginCardNumberField())
        checkError = false;
    if (checkDestiCardNumberField())
        checkError = false;
    if (checkAmountField())
        checkError = false;

    if (checkError) {
        continuePBClick();
    }
}

void Transfer::setIdx() {
    for (int i = 0; i < users.getBankAccountNum(); i++) {
        if (users.getSingleBankAccount(i).getBankCard().getCardNumber() == ui->originCardNumberCB->currentText()) {
            this->bankAccountIdx = i;
            return;
        }
    }
}

bool Transfer::checkSameCardNumbers() {
    if (ui->originCardNumberCB->currentText() == ui->destiCardNumberLE->text()) {
        ui->destiCardNmuberError->setText("Card numbers can't be the same");
        ui->destiCardNmuberError->show();
        return true;
    }
    return false;
}

bool Transfer::checkOriginCardNumberField() {
    if (checkOriginExpire()) {
        ui->originCardNumberError->setText("This card has expired");
        ui->originCardNumberError->show();
        return true;
    }
    return false;
}

bool Transfer::checkDestiCardNumberField() {
    if (ui->destiCardNumberLE->text() == "") {
        ui->destiCardNmuberError->setText("This field is empty");
        ui->destiCardNmuberError->show();
        return true;
    }
    else if (checkDestiCardNumber(ui->destiCardNumberLE->text())) {
        ui->destiCardNmuberError->setText("This field is invalid");
        ui->destiCardNmuberError->show();
        return true;
    }
    else if (users.findCardNumber(ui->destiCardNumberLE->text())) {
        ui->destiCardNmuberError->setText("This card number doesn't exist");
        ui->destiCardNmuberError->show();
        return true;
    }
    else if (users.checkDestiExpire(ui->destiCardNumberLE->text())) {
        ui->destiCardNmuberError->setText("This card has expired");
        ui->destiCardNmuberError->show();
        return true;
    }
    return false;
}

bool Transfer::checkAmountField() {
    if (ui->amountLE->text() == "") {
        ui->amountError->setText("This field is empty");
        ui->amountError->show();
        return true;
    }
    else if (checkNumber(ui->amountLE->text())) {
        ui->amountError->setText("This field is invalid");
        ui->amountError->show();
        return true;
    }
    else if (checkBalance(ui->amountLE->text().toLongLong())) {
        ui->amountError->setText("There is not enough balance in your account");
        ui->amountError->show();
        return true;
    }
    else if (checkAmount(ui->amountLE->text().toLongLong())) {
        ui->amountError->setText("This field must be less than 3,000,000T");
        ui->amountError->show();
        return true;
    }
    else if (check24HourTransfer(ui->amountLE->text().toLongLong())) {
        ui->amountError->setText("You can't transfer more than 6,000,000T in a 24h");
        ui->amountError->show();
        return true;
    }
    return false;
}

bool Transfer::checkOriginExpire() {
    tm expirationDate = cards.getExpirationDate();

    if (isBeforeNow(expirationDate)) {
        return true;
    }
    return false;
}

bool Transfer::checkDestiCardNumber(QString cardNumber) {
    if (cardNumber.size() == 16) {
        for (int i = 0; i < cardNumber.length(); i++) {
            if ((cardNumber[i] < '0') || (cardNumber[i] > '9')) {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool Transfer::checkNumber(QString text) {
    if (text.size() < 13) {
        for (int i = 0; i < text.length(); i++) {
            if ((text[i] < '0') || (text[i] > '9')) {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool Transfer::checkBalance(long long int amount) {
    if (bankAccounts.getBalance() >= amount)
        return false;
    return true;
}

bool Transfer::checkAmount(long long int amount) {
    if (amount > 3000000)
        return true;
    return false;
}

bool Transfer::check24HourTransfer(long long int amount) {
    tm last24HourDate = calculatePastDate(24);

    if (isBefore(last24HourDate, bankAccounts.getLastTransferDate())) {
        if (bankAccounts.getLastTransferAmount() + amount > 6000000) {
            return true;
        }
    }

    return false;
}

void Transfer::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}

void Transfer::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}

void Transfer::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}

void Transfer::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}

tm Transfer::getCurrentTime() {
    time_t now = time(nullptr);
    return *localtime(&now);
}

tm Transfer::calculatePastDate(int hours) {
    tm currentDate = getCurrentTime();
    currentDate.tm_hour -= hours;
    mktime(&currentDate);
    return currentDate;
}

bool Transfer::isBeforeNow(const tm& date) {
    time_t now = time(nullptr);
    time_t inputTime = mktime(const_cast<tm*>(&date));
    return inputTime < now;
}

bool Transfer::isBefore(const tm& time12, const tm& time22) {
    time_t time11 = mktime(const_cast<tm*>(&time12));
    time_t time21 = mktime(const_cast<tm*>(&time22));
    return time21 < time11;
}

void Transfer::setUserTransferData() {
    //set to bank account
    bankAccounts.setBankCard(cards);

    //set to user
    users.setSingleBankAccount(bankAccounts, bankAccountIdx);

    //set to list of users
    users.updateUserDataInList(users.getNationalCode());
}
