#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<QString>

enum BankType {
    saving, current, loan
};

class BankAccount {
private:
    BankType bankType;
    QString accountNumber;
    long long int balance;

public:
    BankAccount();
    void setBankType(BankType);
    void setAccountNumber(QString);
    void setBalance(long long int);
    BankType getBankType();
    QString getAccountNumber();
    long long int getBalance();
};

#endif // BANKACCOUNT_H
