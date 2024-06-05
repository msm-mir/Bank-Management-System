#include "cardinfo.h"
#include "ui_cardinfo.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

CardInfo::CardInfo(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::CardInfo) {
    ui->setupUi(this);

    this->users = users;

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    connect(ui->donePB, SIGNAL(clicked()), this, SLOT(openMainPanelPage()));
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
CardInfo::~CardInfo() {
    delete ui;
}
void CardInfo::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}
void CardInfo::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}
void CardInfo::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}
void CardInfo::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}
void CardInfo::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}
void CardInfo::openMainPanelPage() {
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}
void CardInfo::openLogoutPage() {
    LoginSignin *np = new LoginSignin;
    np->show();
    this->close();
}
