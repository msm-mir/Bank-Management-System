#include "loginsignup.h"
#include "ui_loginsignin.h".h"

LoginSignin::LoginSignin(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSignin) {
    ui->setupUi(this);
}
LoginSignin::~LoginSignin() {
    delete ui;
}
