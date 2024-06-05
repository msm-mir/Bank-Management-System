#ifndef LOGINSIGNIN_H
#define LOGINSIGNIN_H

#include <QWidget>
#include <QString>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginSignin;
}
QT_END_NAMESPACE

class LoginSignin : public QWidget { Q_OBJECT

private slots:
    void checkSignUp();
    void checkLogIn();
private:
    Ui::LoginSignin *ui;
public:
    User users;

    explicit LoginSignin(QWidget *parent = nullptr);
    ~LoginSignin();

    void signUpPBClick();
    void logInPBClick();
    void hideError();
    bool checkString(QString);
    bool checkName(QString);
    bool checkAge(QString);
    bool checkNationalCode(QString);
    void clearLineEdits();
    bool checkFirstNameField();
    bool checkLastNameField();
    bool checkNationalCodeField();
    bool checkAgeField();
    bool checkSignupUsernameField();
    bool checkSignupPasswordField();
    bool checkLoginUsernameField();
    bool checkLoginPasswordField();
};

#endif // LOGINSIGNIN_H
