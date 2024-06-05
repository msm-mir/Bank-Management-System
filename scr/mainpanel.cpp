#include "mainpanel.h"
#include "ui_mainpanel.h"
#include "user.h"

MainPanel::MainPanel(User user, QWidget *parent) : QWidget(parent) , ui(new Ui::MainPanel) {
    ui->setupUi(this);
    this->user = user;
    addInfo();
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
