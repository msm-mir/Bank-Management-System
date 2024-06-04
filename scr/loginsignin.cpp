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
    checkSignUp();

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

    ui->firstNameInvalidError->hide();
    ui->lastNameInvalidError->hide();
    ui->nationalCodeInvalidError->hide();
    ui->ageInvalidError->hide();
    ui->signupUsernameInvalidError->hide();
    ui->signupPasswordInvalidError->hide();

}

void LoginSignin::checkSignUp() {
    bool checkError = true;

    //check first name field
    if (ui->firstNameLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->firstNameLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check last name field
    if (ui->lastNameLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->lastNameLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check national code field
    if (ui->nationalCodeLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->nationalCodeLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check age field
    if (ui->ageLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->ageLE->text().toStdString())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check username field
    if (ui->signUpUsernameLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->signUpUsernameLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check password field
    if (ui->signUpPasswordLE == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    if (checkString(ui->signUpPasswordLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }
}
