#ifndef CARDINFO_H
#define CARDINFO_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CardInfo;
}
QT_END_NAMESPACE

class CardInfo : public QWidget
{
    Q_OBJECT

private:
    Ui::CardInfo *ui;
private slots:
    void addInfo();
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openTransferPage();
    void openMainPanelPage();
    void openLogoutPage();
public:
    User users;

    explicit CardInfo(User, QWidget *parent = nullptr);
    ~CardInfo();

};

#endif // CARDINFO_H
