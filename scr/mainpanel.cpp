#include "mainpanel.h"
#include "ui_mainpanel.h"
#include "user.h"
#include "list.h"
#include "loginsignin.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

MainPanel::MainPanel(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::MainPanel) {
    ui->setupUi(this);

    this->users = users;
    addInfo();

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
MainPanel::~MainPanel() {
    delete ui;
}
void MainPanel::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}
void MainPanel::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}
void MainPanel::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}
void MainPanel::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}
void MainPanel::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}
void MainPanel::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}
