#include "viewbalance.h"
#include "ui_viewbalance.h"

ViewBalance::ViewBalance(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewBalance)
{
    ui->setupUi(this);
}

ViewBalance::~ViewBalance()
{
    delete ui;
}
