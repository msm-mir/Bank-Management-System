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
    this->bankAccounts = users.getSingleBankAccount(users.getBankAccountNum() - 1);
    this->cards = users.getSingleBankAccount(users.getBankAccountNum() - 1).getBankCard();
    addInfo();    

    //click to open pages
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));

    //click change password push button
    connect(ui->changePasswordsPB, SIGNAL(clicked()), this, SLOT(checkChangePassword()));

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
}

void ChangePassword::changePasswordPBClick() {
    setUserChangePasswordData();

    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
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

void ChangePassword::checkChangePassword() {

}

void ChangePassword::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}

void ChangePassword::setUserChangePasswordData() {
    //set initial balance
    bankAccounts.setBalance(ui->initialBalanceLE->text());

    //set 4 digit password
    cards.setFourDigitPassword(ui->fourDigitPasswordLE->text());

    //set fixed password
    if (ui->fixedPasswordLE->text() != "") {
        cards.setFixedPassword(ui->fixedPasswordLE->text());
        cards.setHaveFixedPassword(true);
    }
    else
        cards.setHaveFixedPassword(false);

    //set to bank account
    bankAccounts.setBankCard(cards);

    //set to user
    users.setSingleBankAccount(bankAccounts, users.getBankAccountNum() - 1);

    //set to list of users
    users.updateUserDataInList(users.getNationalCode());
}
