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
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}

void LoginSignin::hideError() {
    ui->firstNameError->hide();
    ui->lastNameError->hide();
    ui->nationalCodeError->hide();
    ui->ageError->hide();
    ui->signupUsernameError->hide();
    ui->signupPasswordError->hide();

    ui->loginUsernameError->hide();
    ui->loginPasswordError->hide();
}

void LoginSignin::checkSignUp() {
    hideError();

    bool checkError = true;

    checkError = checkFirstNameField();
    checkError = checkLastNameField();
    checkError = checkNationalCodeField();
    checkError = checkAgeField();
    checkError = checkSignupUsernameField();
    checkError = checkSignupPasswordField();

    if (checkError) {
        signUpPBClick();
    }
}

void LoginSignin::checkLogIn() {
    hideError();

    bool checkError = true;

    checkError = checkLoginUsernameField();
    checkError = checkLoginPasswordField();

    users.setUserInfo(ui->loginUsernameLE->text(), ui->loginPasswordLE->text());

    if (checkError) {
        logInPBClick();
    }
}

bool LoginSignin::checkString(QString text) {
    int cntLetter = 0;
    for (int i = 0; i < text.size(); i++) {
        if (((text[i] >= 'A') && (text[i] <= 'Z')) || ((text[i] >= 'a') && (text[i] <= 'z'))) {
            cntLetter++;
        }
    }
    if (cntLetter >= 4) {
        for (int i = 0; i < text.size(); i++) {
            if (((text[i] < 'A') || (text[i] > 'z')) || ((text[i] < 'a') && (text[i] > 'Z'))) {
                if ((text[i] == '.') || (text[i] == '_') || ((text[i] >= '0') && (text[i] <='9')))
                    continue;
                else
                    return true;
            }
        }
        return false;
    }
    return true;
}

bool LoginSignin::checkName(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if (((text[i] >= 'A') && (text[i] <= 'Z')) || ((text[i] >= 'a') && (text[i] <= 'z'))) {
            if (text.size() >= 3)
                return false;
        }
    }
    return true;
}

bool LoginSignin::checkAge(QString text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] >= '0') && (text[i] <= '9')) {
            int number = text.toInt();
            if (number >= 18 && number <= 100)
                return false;
        }
    }
    return true;
}

bool LoginSignin::checkNationalCode(QString text) {
    if (text.size() == 10) {
        for (int i = 0; i < text.length(); i++) {
            if ((text[i] >= '0') && (text[i] <= '9')) {
                return false;
            }
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

bool LoginSignin::checkFirstNameField() {
    if (ui->firstNameLE->text() == "") {
        ui->firstNameError->setText("This field is empty");
        ui->firstNameError->show();
        return false;
    }
    else if (checkName(ui->firstNameLE->text())) {
        ui->firstNameError->setText("This field is invalid");
        ui->firstNameError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkLastNameField() {
    if (ui->lastNameLE->text() == "") {
        ui->lastNameError->setText("This field is empty");
        ui->lastNameError->show();
        return false;
    }
    else if (checkName(ui->lastNameLE->text())) {
        ui->lastNameError->setText("This field is invalid");
        ui->lastNameError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkNationalCodeField() {
    if (ui->nationalCodeLE->text() == "") {
        ui->nationalCodeError->setText("This field is empty");
        ui->nationalCodeError->show();
        return false;
    }
    else if (checkNationalCode(ui->nationalCodeLE->text())) {
        ui->nationalCodeError->setText("This field is invalid");
        ui->nationalCodeError->show();
        return false;
    }
    else if (users.uniqueNationalCode(ui->nationalCodeLE->text())) {
        ui->nationalCodeError->setText("The national code already exists");
        ui->nationalCodeError->show();
        if (users.uniqueName(ui->firstNameLE->text()) || users.uniqueFamily(ui->lastNameLE->text())) {
            if (users.uniqueName(ui->firstNameLE->text())) {
                ui->firstNameError->setText("The first name already exists");
                ui->firstNameError->show();
            }
            if (users.uniqueFamily(ui->lastNameLE->text())) {
                ui->lastNameError->setText("The last name already exists");
                ui->lastNameError->show();
            }
        }
        return false;
    }
    return true;
}

bool LoginSignin::checkAgeField() {
    if (ui->ageLE->text() == "") {
        ui->ageError->setText("This field is empty");
        ui->ageError->show();
        return false;
    }
    else if (checkAge(ui->ageLE->text())) {
        ui->ageError->setText("This field is invalid");
        ui->ageError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkSignupUsernameField() {
    if (ui->signUpUsernameLE->text() == "") {
        ui->signupUsernameError->setText("This field is empty");
        ui->signupUsernameError->show();
        return false;
    }
    else if (checkString(ui->signUpUsernameLE->text())) {
        ui->signupUsernameError->setText("This field is invalid");
        ui->signupUsernameError->show();
        return false;
    }
    else if (users.uniqueUsername(ui->signUpUsernameLE->text())) {
        ui->signupUsernameError->setText("The username already exists");
        ui->signupUsernameError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkSignupPasswordField() {
    if (ui->signUpPasswordLE->text() == "") {
        ui->signupPasswordError->setText("This field is empty");
        ui->signupPasswordError->show();
        return false;
    }
    else if (checkString(ui->signUpPasswordLE->text())) {
        ui->signupPasswordError->setText("This field is invalid");
        ui->signupPasswordError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkLoginUsernameField() {
    QString username = ui->loginUsernameLE->text();
    QString password = ui->loginPasswordLE->text();
    QString output = users.find(username, password);

    if (ui->loginUsernameLE->text() == "") {
        ui->loginUsernameError->setText("This field is empty");
        ui->loginUsernameError->show();
        return false;
    }
    else if (checkString(ui->loginUsernameLE->text())) {
        ui->loginUsernameError->setText("This field is invalid");
        ui->loginUsernameError->show();
        return false;
    }
    else if (output == "non-existence of username") {
        ui->loginUsernameError->setText("The username doesn't exist");
        ui->loginUsernameError->show();
        return false;
    }
    return true;
}

bool LoginSignin::checkLoginPasswordField() {
    QString username = ui->loginUsernameLE->text();
    QString password = ui->loginPasswordLE->text();
    QString output = users.find(username, password);

    if (ui->loginPasswordLE->text() == "") {
        ui->loginPasswordError->setText("This field is empty");
        ui->loginPasswordError->show();
        return false;
    }
    else if (checkString(ui->loginPasswordLE->text())) {
        ui->loginPasswordError->setText("This field is invalid");
        ui->loginPasswordError->show();
        return false;
    }
    else if (output == "incorrect password") {
        ui->loginUsernameError->setText("The password is incorrect");
        ui->loginUsernameError->show();
        return false;
    }
    return true;
}
