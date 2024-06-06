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
    QString balance = 0;
    Card bankCard;

public:
    BankAccount();
    ~BankAccount();

    void setBankType(BankType);
    void setBankAccountNumber(QString);
    void setBalance(QString);
    void setBankCard(Card);

    BankType getBankType();
    QString getBankAccountNumber();
    QString getBalance();
    Card getBankCard();
};

#endif // BANKACCOUNT_H
