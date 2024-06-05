#include "mainpanel.h"
#include "ui_mainpanel.h"
#include "user.h"

MainPanel::MainPanel(User user, QWidget *parent) : QWidget(parent) , ui(new Ui::MainPanel) {
    ui->setupUi(this);

    this->user = user;
    addInfo();

    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT());
}
MainPanel::~MainPanel() {
    delete ui;
}
void MainPanel::addInfo() {
    ui->firstNameST->setText(user.getName());
    ui->lastNameST->setText(user.getFamily());
    ui->nationalCodeST->setText(user.getNationalCode());
    ui->ageST->setText(QString::number(user.getAge()));
}
void MainPanel::openCreateBankAccountPage() {

}
void MainPanel::openChangePasswordPage() {

}
void MainPanel::openViewBalancePage() {

}
void MainPanel::openTransferPage() {

}
void MainPanel::logoutPBClick() {

}
