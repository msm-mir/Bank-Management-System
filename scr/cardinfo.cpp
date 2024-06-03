#include "cardinfo.h"
#include "ui_cardinfo.h"

CardInfo::CardInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardInfo)
{
    ui->setupUi(this);
}

CardInfo::~CardInfo()
{
    delete ui;
}
