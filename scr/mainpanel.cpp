#include "mainpanel.h"
#include "ui_mainpanel.h"
#include "user.h"

MainPanel::MainPanel(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::MainPanel) {
    ui->setupUi(this);
}

MainPanel::~MainPanel() {
    delete ui;
}
