#include "loginsignin.h"
#include "ui_loginsignin.h"
#include "list.h"
#include "user.h"

using namespace std;

LoginSignin::LoginSignin(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSignin) {
    ui->setupUi(this);

    hideError();

    connect(ui->signUpPB, SIGNAL(clicked()), this, SLOT(checkSignUp()));
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

    ui->firstNameInvalidError->hide();
    ui->lastNameInvalidError->hide();
    ui->nationalCodeInvalidError->hide();
    ui->ageInvalidError->hide();
    ui->signupUsernameInvalidError->hide();
    ui->signupPasswordInvalidError->hide();

    ui->loginUsernameEmptyError->hide();
    ui->loginPasswordEmptyError->hide();

    ui->loginUsernameInvalidError->hide();
    ui->loginPasswordInvalidError->hide();
}

void LoginSignin::checkSignUp() {
    hideError();

    bool checkError = false;

    //check first name field
    if (ui->firstNameLE->text() == "") {
        checkError = true;
        ui->firstNameEmptyError->show();
    }
    else if (checkString(ui->firstNameLE->text())) {
        checkError = true;
        ui->firstNameInvalidError->show();
    }

    //check last name field
    if (ui->lastNameLE->text() == "") {
        checkError = true;
        ui->lastNameEmptyError->show();
    }
    else if (checkString(ui->lastNameLE->text())) {
        checkError = true;
        ui->lastNameInvalidError->show();
    }

    //check national code field
    if (ui->nationalCodeLE->text() == "") {
        checkError = true;
        ui->nationalCodeEmptyError->show();
    }
    else if (checkInt(ui->nationalCodeLE->text()) || checkNationalCode(ui->nationalCodeLE->text())) {
        checkError = true;
        ui->nationalCodeInvalidError->show();
    }

    //check age field
    if (ui->ageLE->text() == "") {
        checkError = true;
        ui->ageEmptyError->show();
    }
    else if (checkInt(ui->ageLE->text()) || checkAge(ui->ageLE->text())) {
        checkError = true;
        ui->ageInvalidError->show();
    }

    //check username field
    if (ui->signUpUsernameLE->text() == "") {
        checkError = true;
        ui->signupUsernameEmptyError->show();
    }
    else if (checkString(ui->signUpUsernameLE->text())) {
        checkError = true;
        ui->signupUsernameInvalidError->show();
    }

    //check password field
    if (ui->signUpPasswordLE->text() == "") {
        checkError = true;
        ui->signupPasswordEmptyError->show();
    }
    else if (checkString(ui->signUpPasswordLE->text())) {
        checkError = true;
        ui->signupPasswordInvalidError->show();
    }

    if (!checkError) {
        signUpPBClick();
    }
}

bool LoginSignin::checkString(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] < 'A') || (text[i] > 'z') || ((text[i] < 'a') && (text[i] > 'Z'))) {
            return true;
        }
    }
    return false;
}

bool LoginSignin::checkInt(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] < '0') || (text[i] > '9')) {
            return true;
        }
    }
    return false;
}

bool LoginSignin::checkAge(QString text) {
    if (text.size() == 1 || text.size() == 2) {
        return false;
    }
    return true;
}

bool LoginSignin::checkNationalCode(QString text) {
    if (text.size() == 10) {
        return false;
    }
    return true;
}
