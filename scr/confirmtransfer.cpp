#include "confirmtransfer.h"
#include "ui_confirmtransfer.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

ConfirmTransfer::ConfirmTransfer(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::ConfirmTransfer) {
    ui->setupUi(this);

    this->users = users;

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->PasswordReqPB, SIGNAL(clicked()), this, SLOT());
    connect(ui->confirmPB, SIGNAL(clicked()), this, SLOT(openMainPanelPage()));
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
ConfirmTransfer::~ConfirmTransfer() {
    delete ui;
}
void ConfirmTransfer::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}
void ConfirmTransfer::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}
void ConfirmTransfer::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}
void ConfirmTransfer::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}
void ConfirmTransfer::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}
void ConfirmTransfer::openMainPanelPage() {
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}
void ConfirmTransfer::openLogoutPage() {
    LoginSignin *np = new LoginSignin;
    np->show();
    this->close();
}
