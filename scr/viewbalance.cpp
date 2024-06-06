#include "viewbalance.h"
#include "ui_viewbalance.h"
#include "user.h"
#include "loginsignin.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "transfer.h"

ViewBalance::ViewBalance(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::ViewBalance) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT());
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
ViewBalance::~ViewBalance() {
    delete ui;
}
void ViewBalance::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}
void ViewBalance::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}
void ViewBalance::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}
void ViewBalance::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}
void ViewBalance::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}
