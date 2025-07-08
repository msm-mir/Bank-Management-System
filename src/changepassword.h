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
    void change4DigitPasswordPBClick();
    void changeFixedPasswordPBClick();
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
    void setIdx();
    bool checkNew4DigitPasswordField();
    bool checkNewFixedPasswordField();
    bool checkNumber(QString);
    bool checkFourDigitPassword(QString);
    bool checkFixedPassword(QString);
    bool equal4DigitPassword(QString);
    bool equalFixedPassword(QString);
    void finalUserSet4Digit();
    void finalUserSetFixed();
};

#endif // CHANGEPASSWORD_H
