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
    void checkTransfer();
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openLogoutPage();
public:
    User users;
    BankAccount bankAccounts;
    Card cards;
    int bankAccountIdx;

    explicit Transfer(User, QWidget *parent = nullptr);
    ~Transfer();

    void addInfo();
    void continuePBClick();
    void hideError();
    void setIdx();
    bool checkSameCardNumbers();
    bool checkOriginCardNumberField();
    bool checkDestiCardNumberField();
    bool checkAmountField();
    bool checkOriginExpire();
    bool checkDestiCardNumber(QString);
    bool checkNumber(QString);
    bool checkBalance(long long int);
    bool checkAmount(long long int);
    bool check24HourTransfer(long long int);
    tm getCurrentTime();
    tm calculatePastDate(int);
    tm calculateFutureDate(int);
    bool isBeforeNow(const tm&);
    bool isBefore(const tm&, const tm&);
    void setUserTransferData();
};

#endif // TRANSFER_H
