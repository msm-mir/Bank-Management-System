#include "mainpanel.h"
#include "ui_mainpanel.h"
#include "user.h"
#include "list.h"
#include "loginsignin.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

#include <QKeyEvent>
#include <QPushButton>

MainPanel::MainPanel(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::MainPanel) {
    ui->setupUi(this);

    //disable maximize
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    this->users = users;
    addInfo();

    //click to open pages
    if (users.getBankAccountNum() != 0) {
        connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
        connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
        connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));
    }

    //click to open page
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));

    //set cursor focus
    ui->logoutPB->setFocus();
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
