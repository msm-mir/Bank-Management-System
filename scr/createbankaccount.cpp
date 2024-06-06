#include "createbankaccount.h"
#include "ui_createbankaccount.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

CreateBankAccount::CreateBankAccount(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::CreateBankAccount) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    //click to open pages
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));

    //click create push button
    connect(ui->createPB, SIGNAL(clicked()), this, SLOT(openMainPanelPage()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));


}
CreateBankAccount::~CreateBankAccount() {
    delete ui;
}
void CreateBankAccount::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}
void CreateBankAccount::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}
void CreateBankAccount::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}
void CreateBankAccount::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}
void CreateBankAccount::openMainPanelPage() {
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}
void CreateBankAccount::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}
