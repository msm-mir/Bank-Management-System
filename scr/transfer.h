#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Transfer;
}
QT_END_NAMESPACE

class Transfer : public QWidget
{
    Q_OBJECT

private:
    Ui::Transfer *ui;
private slots:
    void addInfo();
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openConfirmTransferPage();
    void openLogoutPage();
public:
    User users;

    explicit Transfer(User, QWidget *parent = nullptr);
    ~Transfer();

};

#endif // TRANSFER_H
