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
    void openChangePasswordPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
public:
    User users;

    explicit CreateBankAccount(User, QWidget *parent = nullptr);
    ~CreateBankAccount();

};

#endif // CREATEBANKACCOUNT_H
