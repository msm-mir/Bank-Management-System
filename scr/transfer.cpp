#include "transfer.h"
#include "ui_transfer.h"
#include "user.h"
#include "loginsignin.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "confirmtransfer.h"

Transfer::Transfer(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::Transfer) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    //click to open pages
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));

    //click view balance push button
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));

    //click continue push button
    connect(ui->continuePB, SIGNAL(clicked()), this, SLOT(openConfirmTransferPage()));

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
void Transfer::openConfirmTransferPage() {
    ConfirmTransfer *np = new ConfirmTransfer(users);
    np->show();
    this->close();
}
void Transfer::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}
