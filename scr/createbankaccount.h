#ifndef CREATEBANKACCOUNT_H
#define CREATEBANKACCOUNT_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CreateBankAccount;
}
QT_END_NAMESPACE

class CreateBankAccount : public QWidget
{
    Q_OBJECT

private:
    Ui::CreateBankAccount *ui;
private slots:
    void addInfo();
    void createPBClick();
    void hideError();
    void checkCreateAccount();
    bool checkBalanceField();
    bool check4DigitPasswordField();
    bool checkFixedPasswordField();
    bool checkNumber(QString);
    bool checkBalance(QString);
    bool checkFourDigitPassword(QString);
    bool checkFixedPassword(QString);
    void setUserBankAccountData();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openTransferPage();
    void openLogoutPage();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;

    explicit CreateBankAccount(User, QWidget *parent = nullptr);
    ~CreateBankAccount();

};

#endif // CREATEBANKACCOUNT_H
