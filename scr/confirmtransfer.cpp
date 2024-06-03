#include "confirmtransfer.h"
#include "ui_confirmtransfer.h"

ConfirmTransfer::ConfirmTransfer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConfirmTransfer)
{
    ui->setupUi(this);
}

ConfirmTransfer::~ConfirmTransfer()
{
    delete ui;
}
