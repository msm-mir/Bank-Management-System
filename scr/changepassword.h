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
    void openCreateBankAccountPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
public:
    User users;

    explicit ChangePassword(User, QWidget *parent = nullptr);
    ~ChangePassword();

};

#endif // CHANGEPASSWORD_H
