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
    QString bankAccountNum;
    long long int balance;
    Card bankCard;

public:
    BankAccount();
    ~BankAccount();

    void setBankType(BankType);
    void setBankAccountNumber(QString);
    void setBalance(long long int);
    void setBankCard(Card);

    BankType getBankType();
    QString getBankAccountNumber();
    long long int getBalance();
    Card getBankCard();
};

#endif // BANKACCOUNT_H
