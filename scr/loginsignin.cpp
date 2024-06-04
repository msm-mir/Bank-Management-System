#include "loginsignin.h"
#include "ui_loginsignin.h"
#include "list.h"
#include "user.h"

using namespace std;

LoginSignin::LoginSignin(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSignin) {
    ui->setupUi(this);

    hideError();

    connect(ui->signUpPB, SIGNAL(clicked()), this, SLOT(signUpPBClick()));
}
LoginSignin::~LoginSignin() {
    delete ui;
}

void LoginSignin::signUpPBClick() {
    User users;
    users.setName(ui->firstNameLE->text());
    users.setFamily(ui->lastNameLE->text());
    users.setNationalCode(ui->nationalCodeLE->text());
    users.setAge(ui->ageLE->text().toInt());
    users.setUniqueUsername(ui->signUpUsernameLE->text());
    users.setPassword(ui->signUpPasswordLE->text());

    List<User> listUsers;
    listUsers.pushBack(users);
}

void LoginSignin::hideError() {
    ui->firstNameEmptyError->hide();
    ui->lastNameEmptyError->hide();
    ui->nationalCodeEmptyError->hide();
    ui->ageEmptyError->hide();
    ui->signupUsernameEmptyError->hide();
    ui->signupPasswordEmptyError->hide();
}
