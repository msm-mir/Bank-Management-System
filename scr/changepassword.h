#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ChangePassword;
}
QT_END_NAMESPACE

class ChangePassword : public QWidget
{
    Q_OBJECT

private:
    Ui::ChangePassword *ui;
private slots:
    void checkChange4DigitPassword();
    void checkChangeFixedPassword();
    void openCreateBankAccountPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;
    int bankAccountIdx;

    explicit ChangePassword(User, QWidget *parent = nullptr);
    ~ChangePassword();

    void addInfo();
    void hideError();
    void change4DigitPasswordPBClick();
    void changeFixedPasswordPBClick();
    void setIdx();
    bool checkNew4DigitPasswordField();
    bool checkNewFixedPasswordField();
    bool checkNumber(QString);
    bool checkFourDigitPassword(QString);
    bool checkFixedPassword(QString);
    bool equal4DigitPassword(QString);
    bool equalFixedPassword(QString);
    void setUserChange4DigitPasswordData();
    void setUserChangeFixedPasswordData();
};

#endif // CHANGEPASSWORD_H
