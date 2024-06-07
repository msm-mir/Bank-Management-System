#include "loginsignin.h"
#include "ui_loginsignin.h"
#include "list.h"
#include "user.h"
#include "mainpanel.h"

using namespace std;

LoginSignin::LoginSignin(User users, QWidget *parent) : QWidget(parent), ui(new Ui::LoginSignin) {
    ui->setupUi(this);

    this->users = users;

    hideError();

    //click to sign up
    connect(ui->signUpPB, SIGNAL(clicked()), this, SLOT(checkSignUp()));

    //click to log in
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

    //for not changing checkError from false to true
    if (checkFirstNameField())
        checkError = false;
    if (checkLastNameField())
        checkError = false;
    if (checkNationalCodeField())
        checkError = false;
    if (checkAgeField() == false)
        checkError = false;
    if (checkSignupUsernameField())
        checkError = false;
    if (checkSignupPasswordField())
        checkError = false;

    if (checkError) {
        signUpPBClick();
    }
}

void LoginSignin::checkLogIn() {
    hideError();

    bool checkError = true;

    //for not changing checkError from false to true
    if (checkLoginUsernameField())
        checkError = false;
    if (checkLoginPasswordField())
        checkError = false;

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

bool LoginSignin::checkName(QString name) {
    if (name.size() >= 3 && name.size() <= 12) {
        for (int i = 0; i < name.length(); i++) {
            if ((name[i] < 'A') || (name[i] > 'z') || ((name[i] < 'a') && (name[i] > 'Z'))) {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool LoginSignin::checkAge(QString age) {
    int number = age.toInt();
    if (number >= 18 && number <= 100) {
        for (int i = 0; i < age.length(); i++) {
            if ((age[i] < '0') || (age[i] > '9')) {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool LoginSignin::checkNationalCode(QString nationalCode) {
    if (nationalCode.size() == 10) {
        for (int i = 0; i < nationalCode.length(); i++) {
            if ((nationalCode[i] < '0') || (nationalCode[i] > '9')) {
                return true;
            }
        }
        return false;
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
        return true;
    }
    else if (checkName(ui->firstNameLE->text())) {
        ui->firstNameError->setText("This field is invalid");
        ui->firstNameError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkLastNameField() {
    if (ui->lastNameLE->text() == "") {
        ui->lastNameError->setText("This field is empty");
        ui->lastNameError->show();
        return true;
    }
    else if (checkName(ui->lastNameLE->text())) {
        ui->lastNameError->setText("This field is invalid");
        ui->lastNameError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkNationalCodeField() {
    if (ui->nationalCodeLE->text() == "") {
        ui->nationalCodeError->setText("This field is empty");
        ui->nationalCodeError->show();
        return true;
    }
    else if (checkNationalCode(ui->nationalCodeLE->text())) {
        ui->nationalCodeError->setText("This field is invalid");
        ui->nationalCodeError->show();
        return true;
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
        return true;
    }
    return false;
}

bool LoginSignin::checkAgeField() {
    if (ui->ageLE->text() == "") {
        ui->ageError->setText("This field is empty");
        ui->ageError->show();
        return true;
    }
    else if (checkAge(ui->ageLE->text())) {
        ui->ageError->setText("This field is invalid");
        ui->ageError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkSignupUsernameField() {
    if (ui->signUpUsernameLE->text() == "") {
        ui->signupUsernameError->setText("This field is empty");
        ui->signupUsernameError->show();
        return true;
    }
    else if (checkString(ui->signUpUsernameLE->text())) {
        ui->signupUsernameError->setText("This field is invalid");
        ui->signupUsernameError->show();
        return true;
    }
    else if (users.uniqueUsername(ui->signUpUsernameLE->text())) {
        ui->signupUsernameError->setText("The username already exists");
        ui->signupUsernameError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkSignupPasswordField() {
    if (ui->signUpPasswordLE->text() == "") {
        ui->signupPasswordError->setText("This field is empty");
        ui->signupPasswordError->show();
        return true;
    }
    else if (checkString(ui->signUpPasswordLE->text())) {
        ui->signupPasswordError->setText("This field is invalid");
        ui->signupPasswordError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkLoginUsernameField() {
    QString username = ui->loginUsernameLE->text();
    QString password = ui->loginPasswordLE->text();
    QString output = users.loginFind(username, password);

    if (ui->loginUsernameLE->text() == "") {
        ui->loginUsernameError->setText("This field is empty");
        ui->loginUsernameError->show();
        return true;
    }
    else if (checkString(ui->loginUsernameLE->text())) {
        ui->loginUsernameError->setText("This field is invalid");
        ui->loginUsernameError->show();
        return true;
    }
    else if (output == "non-existence of username") {
        ui->loginUsernameError->setText("The username doesn't exist");
        ui->loginUsernameError->show();
        return true;
    }
    return false;
}

bool LoginSignin::checkLoginPasswordField() {
    QString username = ui->loginUsernameLE->text();
    QString password = ui->loginPasswordLE->text();
    QString output = users.loginFind(username, password);

    if (ui->loginPasswordLE->text() == "") {
        ui->loginPasswordError->setText("This field is empty");
        ui->loginPasswordError->show();
        return true;
    }
    else if (checkString(ui->loginPasswordLE->text())) {
        ui->loginPasswordError->setText("This field is invalid");
        ui->loginPasswordError->show();
        return true;
    }
    else if (output == "incorrect password") {
        ui->loginPasswordError->setText("The password is incorrect");
        ui->loginPasswordError->show();
        return true;
    }
    return false;
}
