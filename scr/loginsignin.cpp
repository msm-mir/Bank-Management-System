#include "loginsignin.h"
#include "ui_loginsignin.h"
#include "list.h"
#include "user.h"
#include "mainpanel.h"

using namespace std;

LoginSignin::LoginSignin(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSignin) {
    ui->setupUi(this);

    hideError();
    connect(ui->signUpPB, SIGNAL(clicked()), this, SLOT(checkSignUp()));

    hideError();
    connect(ui->loginPB, SIGNAL(clicked()), this, SLOT(checkLogIn()));
}

LoginSignin::~LoginSignin() {
    delete ui;
}

void LoginSignin::signUpPBClick() {
    users.setName(ui->firstNameLE->text());
    users.setFamily(ui->lastNameLE->text());
    users.setNationalCode(ui->nationalCodeLE->text());
    users.setAge(ui->ageLE->text().toInt());
    users.setUniqueUsername(ui->signUpUsernameLE->text());
    users.setPassword(ui->signUpPasswordLE->text());

    users.addUser();

    clearLineEdits();
}

void LoginSignin::logInPBClick() {
    clearLineEdits();

    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();

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

    ui->firstNameIncorrectError->hide();
    ui->lastNameIncorrectError->hide();
    ui->nationalCodeIncorrectError->hide();
    ui->ageIncorrectError->hide();
    ui->signupUsernameIncorrectError->hide();
    ui->signupPasswordIncorrectError->hide();

    ui->loginUsernameEmptyError->hide();
    ui->loginPasswordEmptyError->hide();

    ui->loginUsernameInvalidError->hide();
    ui->loginPasswordInvalidError->hide();

    ui->loginUsernameIncorrectError->hide();
    ui->loginPasswordIncorrectError->hide();
}

void LoginSignin::checkSignUp() {
    hideError();

    bool checkError = true;

    //check first name field
    if (ui->firstNameLE->text() == "") {
        checkError = false;
        ui->firstNameEmptyError->show();
    }
    else if (checkString(ui->firstNameLE->text())) {
        checkError = false;
        ui->firstNameInvalidError->show();
    }

    //check last name field
    if (ui->lastNameLE->text() == "") {
        checkError = false;
        ui->lastNameEmptyError->show();
    }
    else if (checkString(ui->lastNameLE->text())) {
        checkError = false;
        ui->lastNameInvalidError->show();
    }

    //check national code field
    if (ui->nationalCodeLE->text() == "") {
        checkError = false;
        ui->nationalCodeEmptyError->show();
    }
    else if (checkInt(ui->nationalCodeLE->text()) || checkNationalCode(ui->nationalCodeLE->text())) {
        checkError = false;
        ui->nationalCodeInvalidError->show();
    }
    else if (users.uniqueNationalCode(ui->nationalCodeLE->text())) {
        checkError = false;
        ui->nationalCodeIncorrectError->show();
        if (users.uniqueName(ui->firstNameLE->text())) {
            if (users.uniqueFamily(ui->lastNameLE->text())) {
                if (users.uniqueAge(ui->ageLE->text().toInt())) {
                    ui->firstNameIncorrectError->show();
                    ui->lastNameIncorrectError->show();
                    ui->ageIncorrectError->show();
                }
            }
        }
    }

    //check age field
    if (ui->ageLE->text() == "") {
        checkError = false;
        ui->ageEmptyError->show();
    }
    else if (checkInt(ui->ageLE->text()) || checkAge(ui->ageLE->text())) {
        checkError = false;
        ui->ageInvalidError->show();
    }

    //check username field
    if (ui->signUpUsernameLE->text() == "") {
        checkError = false;
        ui->signupUsernameEmptyError->show();
    }
    else if (checkString(ui->signUpUsernameLE->text())) {
        checkError = false;
        ui->signupUsernameInvalidError->show();
    }
    else if (users.uniqueUsername(ui->signUpUsernameLE->text())) {
        checkError = false;
        ui->signupUsernameIncorrectError->show();
    }

    //check password field
    if (ui->signUpPasswordLE->text() == "") {
        checkError = false;
        ui->signupPasswordEmptyError->show();
    }
    else if (checkString(ui->signUpPasswordLE->text())) {
        checkError = false;
        ui->signupPasswordInvalidError->show();
    }

    if (checkError) {
        signUpPBClick();
    }
}

void LoginSignin::checkLogIn() {
    hideError();

    bool checkError = true;

    //check username field
    if (ui->loginUsernameLE->text() == "") {
        checkError = false;
        ui->loginUsernameEmptyError->show();
    }
    else if (checkString(ui->loginUsernameLE->text())) {
        checkError = false;
        ui->loginUsernameInvalidError->show();
    }

    //check password field
    if (ui->loginPasswordLE->text() == "") {
        checkError = false;
        ui->loginPasswordEmptyError->show();
    }
    else if (checkString(ui->loginPasswordLE->text())) {
        checkError = false;
        ui->loginPasswordInvalidError->show();
    }

    //check username password
    else if (users.find(ui->loginUsernameLE->text(), ui->loginPasswordLE->text())) {
        checkError = false;
        ui->loginUsernameIncorrectError->show();
        ui->loginPasswordIncorrectError->show();
    }

    users.setUserInfo(ui->loginUsernameLE->text(), ui->loginPasswordLE->text());

    if (checkError) {
        logInPBClick();
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
    if ((text.size() == 1 || text.size() == 2) && (text.toInt() != 0)) {
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

bool LoginSignin::checkUsernameAndPassword(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] != '.') || (text[i] != '_')) {
            return false;
        }
    }
    return true;
}

void LoginSignin::clearLineEdits() {
    ui->firstNameLE->clear();
    ui->lastNameLE->clear();
    ui->nationalCodeLE->clear();
    ui->ageLE->clear();
    ui->signUpUsernameLE->clear();
    ui->signUpPasswordLE->clear();
}
