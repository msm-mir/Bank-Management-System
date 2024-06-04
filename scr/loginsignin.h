#ifndef LOGINSIGNIN_H
#define LOGINSIGNIN_H

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginSignin;
}
QT_END_NAMESPACE

class LoginSignin : public QWidget { Q_OBJECT

private slots:
    void checkSignUp();
private:
    Ui::LoginSignin *ui;
public:
    explicit LoginSignin(QWidget *parent = nullptr);
    ~LoginSignin();

    void signUpPBClick();
    void hideError();
    bool checkString(QString);
    bool checkInt(QString);
    bool checkAge(QString);
    bool checkNationalCode(QString);
    bool checkUsernameAndPassword(QString);
};

#endif // LOGINSIGNIN_H
