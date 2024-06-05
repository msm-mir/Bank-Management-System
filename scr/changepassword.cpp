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

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->changePasswordsPB, SIGNAL(clicked()), this, SLOT(openMainPanelPage()));
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
    LoginSignin *np = new LoginSignin;
    np->show();
    this->close();
}
