#ifndef CONFIRMTRANSFER_H
#define CONFIRMTRANSFER_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ConfirmTransfer;
}
QT_END_NAMESPACE

class ConfirmTransfer : public QWidget
{
    Q_OBJECT

private:
    Ui::ConfirmTransfer *ui;
private slots:
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;
    int bankAccountIdx;

    explicit ConfirmTransfer(User, QWidget *parent = nullptr);
    ~ConfirmTransfer();

    void addInfo();
};

#endif // CONFIRMTRANSFER_H
