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

    explicit CardInfo(User, QWidget *parent = nullptr);
    ~CardInfo();

    void addInfo();
    void createCardInfo();
    void createCardNumber();
    void createAccountNumber();
    void createCardIbanNumber(std::string);
    void createCardCvv2();
    void createCardExpirationDate();
    tm getCurrentTime();
    tm calculateFutureDate(int);
    int getYear(const tm&);
    int getMonth(const tm&);
    int getDay(const tm&);
    void setUserCardInfo();
};

#endif // CARDINFO_H
