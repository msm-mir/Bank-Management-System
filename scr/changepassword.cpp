#include "changepassword.h"
#include "ui_changepassword.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "viewbalance.h"
#include "transfer.h"

ChangePassword::ChangePassword(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::ChangePassword) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    hideError();

    //click to open pages
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));

    //click change 4 digit password push button
    connect(ui->change4DigitPasswordsPB, SIGNAL(clicked()), this, SLOT(checkChange4DigitPassword()));

    //click change fixed password push button
    connect(ui->changeFixedPasswordsPB, SIGNAL(clicked()), this, SLOT(checkChangeFixedPassword()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
ChangePassword::~ChangePassword() {
    delete ui;
}
void ChangePassword::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));

    //card number combo box
    for (int i = 0; i < users.getBankAccountNum(); i++) {
        ui->cardNumberCB->addItem(users.getSingleBankAccount(i).getBankCard().getCardNumber());
    }
}

void ChangePassword::change4DigitPasswordPBClick() {
    setUserChange4DigitPasswordData();
    openMainPanelPage();
}

void ChangePassword::changeFixedPasswordPBClick() {
    setUserChangeFixedPasswordData();
    openMainPanelPage();
}

void ChangePassword::hideError() {
    ui->new4DigitPasswordError->hide();
    ui->newFixedPasswordError->hide();
}

void ChangePassword::checkChange4DigitPassword() {
    hideError();

    bool checkError = true;

    //set user bank account idx
    setIdx();

    //for not changing checkError from false to true
    if (checkNew4DigitPasswordField())
        checkError = false;

    if (checkError) {
        change4DigitPasswordPBClick();
    }
}

void ChangePassword::checkChangeFixedPassword() {
    hideError();

    bool checkError = true;

    //set user bank account idx
    setIdx();

    //for not changing checkError from false to true
    if (checkNewFixedPasswordField())
        checkError = false;

    if (checkError) {
        changeFixedPasswordPBClick();
    }
}

void ChangePassword::setIdx() {
    for (int i = 0; i < users.getBankAccountNum(); i++) {
        if (users.getSingleBankAccount(i).getBankCard().getCardNumber() == ui->cardNumberCB->currentText()) {
            this->bankAccountIdx = i;
            return;
        }
    }
}

bool ChangePassword::checkNew4DigitPasswordField() {
    if (ui->new4DigitPasswordLE->text() == "") {
        ui->new4DigitPasswordError->setText("This field is empty");
        ui->new4DigitPasswordError->show();
        return true;
    }
    else if (checkNumber(ui->new4DigitPasswordLE->text())) {
        ui->new4DigitPasswordError->setText("This field is invalid");
        ui->new4DigitPasswordError->show();
        return true;
    }
    else if (checkFourDigitPassword(ui->new4DigitPasswordLE->text())) {
        ui->new4DigitPasswordError->setText("This field must be 4 digits");
        ui->new4DigitPasswordError->show();
        return true;
    }
    else if (equal4DigitPassword(ui->new4DigitPasswordLE->text())) {
        ui->new4DigitPasswordError->setText("This password is already available");
        ui->new4DigitPasswordError->show();
        return true;
    }
    return false;
}

bool ChangePassword::checkNewFixedPasswordField() {
    if (ui->newFixedPasswordLE->text() == "") {
        ui->newFixedPasswordError->setText("This field is empty");
        ui->newFixedPasswordError->show();
        return true;
    }
    else if (checkNumber(ui->newFixedPasswordLE->text())) {
        ui->newFixedPasswordError->setText("This field is invalid");
        ui->newFixedPasswordError->show();
        return true;
    }
    else if (checkFixedPassword(ui->newFixedPasswordLE->text())) {
        ui->newFixedPasswordError->setText("This field must be 4 to 12 digits");
        ui->newFixedPasswordError->show();
        return true;
    }
    else if (equalFixedPassword(ui->newFixedPasswordLE->text())) {
        ui->newFixedPasswordError->setText("This password is already available");
        ui->newFixedPasswordError->show();
        return true;
    }
    return false;
}

bool ChangePassword::checkNumber(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] < '0') || (text[i] > '9')) {
            return true;
        }
    }
    return false;
}

bool ChangePassword::checkFourDigitPassword(QString fourDigitPassword) {
    if (fourDigitPassword.size() == 4)
        return false;
    return true;
}

bool ChangePassword::checkFixedPassword(QString fixedPassword) {
    if (fixedPassword.size() >= 4 && fixedPassword.size() <= 12) {
        return false;
    }
    return true;
}

bool ChangePassword::equal4DigitPassword(QString fourDigitPassword) {
    if (users.getSingleBankAccount(bankAccountIdx).getBankCard().getFourDigitPassword() == fourDigitPassword)
        return true;
    return false;
}

bool ChangePassword::equalFixedPassword(QString fixedPassword) {
    if (users.getSingleBankAccount(bankAccountIdx).getBankCard().getFixedPassword() == fixedPassword)
        return true;
    return false;
}

void ChangePassword::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}

void ChangePassword::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}

void ChangePassword::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}

void ChangePassword::openMainPanelPage() {
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}

void ChangePassword::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}

void ChangePassword::setUserChange4DigitPasswordData() {
    //set bank account and card to this
    bankAccounts = users.getSingleBankAccount(bankAccountIdx);
    cards = users.getSingleBankAccount(bankAccountIdx).getBankCard();

    //set 4 digit password
    cards.setFourDigitPassword(ui->new4DigitPasswordLE->text());

    //set to bank account
    bankAccounts.setBankCard(cards);

    //set to user
    users.setSingleBankAccount(bankAccounts, bankAccountIdx);

    //set to list of users
    users.updateUserDataInList(users.getNationalCode());
}

void ChangePassword::setUserChangeFixedPasswordData() {
    //set bank account and card to this
    bankAccounts = users.getSingleBankAccount(bankAccountIdx);
    cards = users.getSingleBankAccount(bankAccountIdx).getBankCard();

    //set fixed password
    cards.setFixedPassword(ui->newFixedPasswordLE->text());

    //set to bank account
    bankAccounts.setBankCard(cards);

    //set to user
    users.setSingleBankAccount(bankAccounts, bankAccountIdx);

    //set to list of users
    users.updateUserDataInList(users.getNationalCode());
}
