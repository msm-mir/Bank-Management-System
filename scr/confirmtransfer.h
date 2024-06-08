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
    void passwordReqPBClick();
    void checkConfirmTransfer();
    void openLogoutPage();
public:
    User originUser;
    BankAccount originBankAccount;
    Card originCard;
    int originBankAccountIdx;

    User destiUser;
    BankAccount destiBankAccount;
    Card destiCard;
    int destiBankAccountIdx;

    long long int amount;

    explicit ConfirmTransfer(User, int, QString, long long int, QWidget *parent = nullptr);
    ~ConfirmTransfer();

    void setUsersDataToThis(User, int, QString, long long int);
    void addInfo();
    void confirmPBClick();
    void hideError();
    bool checkCvv2Field();
    bool checkFixedPasswordField();
    bool checkOneTimePasswordField();
    bool checkNumber(QString);
    bool checkCvv2(QString);
    bool checkFixedPassword(QString);
    bool checkOneTimePassword(QString);
    tm getCurrentTime();
    void setUsersTransferData();
};

#endif // CONFIRMTRANSFER_H
