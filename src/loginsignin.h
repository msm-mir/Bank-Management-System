#ifndef LOGINSIGNIN_H
#define LOGINSIGNIN_H

#include <QWidget>
#include <QString>
#include "user.h"
#include "list.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginSignin;
}
QT_END_NAMESPACE

class LoginSignin : public QWidget { Q_OBJECT

private slots:
    void checkSignUp();
    void checkLogIn();
    void showSignupPasswordClicked();
    void showLoginPasswordClicked();
private:
    Ui::LoginSignin *ui;
public:
    User users;

    explicit LoginSignin(User, QWidget *parent = nullptr);
    ~LoginSignin();

    void signUpPBClick();
    void logInPBClick();
    void hideError();
    bool checkFirstNameField();
    bool checkLastNameField();
    bool checkNationalCodeField();
    bool checkAgeField();
    bool checkSignupUsernameField();
    bool checkSignupPasswordField();
    bool checkLoginUsernameField();
    bool checkLoginPasswordField();
    bool checkString(QString);
    bool checkName(QString);
    bool checkAge(QString);
    bool checkNationalCode(QString);
    void clearLineEdits();
    void setUserData();
};

#endif // LOGINSIGNIN_H
