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
    void addInfo();
    void change4DigitPasswordPBClick();
    void changeFixedPasswordPBClick();
    void hideError();
    void checkChange4DigitPassword();
    void checkChangeFixedPassword();
    bool checkNew4DigitPasswordField();
    bool checkNewFixedPasswordField();
    bool checkNumber(QString);
    bool equal4DigitPassword(QString);
    bool equalFixedPassword(QString);
    void openCreateBankAccountPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
    void setUserChange4DigitPasswordData();
    void setUserChangeFixedPasswordData();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;

    explicit ChangePassword(User, QWidget *parent = nullptr);
    ~ChangePassword();

};

#endif // CHANGEPASSWORD_H
