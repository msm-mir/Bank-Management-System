#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>
#include "card.h"

enum BankType {
    saving, current, loan
};

class BankAccount {
private:
    BankType bankType;
    QString bankAccountNum = "";
    long long int balance = 0;
    Card bankCard;
    tm lastTransferDate;
    long long int lastTransferAmount = 0;

public:
    BankAccount();
    ~BankAccount();

    void setBankType(BankType);
    void setBankAccountNumber(QString);
    void setBalance(long long int);
    void setBankCard(Card);
    void setLastTransferDate(tm);
    void setLastTransferAmount(long long int);

    BankType getBankType();
    QString getBankAccountNumber();
    long long int getBalance();
    Card getBankCard();
    tm getLastTransferDate();
    long long int getLastTransferAmount();
};

#endif // BANKACCOUNT_H
