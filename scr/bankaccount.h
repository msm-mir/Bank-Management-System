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
    QString accountNumber;
    long long int balance;
    Card bankCard;

public:
    BankAccount();
    ~BankAccount();
    void setBankType(BankType);
    void setAccountNumber(QString);
    void setBalance(long long int);
    void setBankCard(Card);
    BankType getBankType();
    QString getAccountNumber();
    long long int getBalance();
    Card getBankCard();
};

#endif // BANKACCOUNT_H
