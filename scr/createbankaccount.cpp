#include "createbankaccount.h"
#include "ui_createbankaccount.h"

CreateBankAccount::CreateBankAccount(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateBankAccount)
{
    ui->setupUi(this);
}

CreateBankAccount::~CreateBankAccount()
{
    delete ui;
}
