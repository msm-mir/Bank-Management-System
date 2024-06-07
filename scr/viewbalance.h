#ifndef VIEWBALANCE_H
#define VIEWBALANCE_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewBalance;
}
QT_END_NAMESPACE

class ViewBalance : public QWidget
{
    Q_OBJECT

private:
    Ui::ViewBalance *ui;
private slots:
    void addInfo();
    void viewBalancePBClick();
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openTransferPage();
    void openLogoutPage();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;

    explicit ViewBalance(User, QWidget *parent = nullptr);
    ~ViewBalance();

};

#endif // VIEWBALANCE_H
