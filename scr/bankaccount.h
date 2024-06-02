#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<QString>

enum BankType {
    saving, current, loan
};

class BankAccount {
private:
    BankType bankType;
    QString cardNumber;
    QString ibanNumber;
    QString accountNumber;
    QString cvv2;
    long long int balance;
    QString expirationDate;
    QString fourDigitPassword;
    QString fixedPassword;
    QString oneTimePassword;

public:
    BankAccount();
    void setBankType(BankType);
    void setCardNumber(QString);
    void setIbanNumber(QString);
    void setAccountNumber(QString);
    void setCvv2(QString);
    void setBalance(long long int);
    void setExpirationDate(QString);
    void setFourDigitPassword(QString);
    void setFixedPassword(QString);
    void setOneTimePassword(QString);
    BankType getBankType();
    QString getCardNumber();
    QString getIbanNumber();
    QString getAccountNumber();
    QString getCvv2();
    long long int getBalance();
    QString getExpirationDate();
    QString getFourDigitPassword();
    QString getFixedPassword();
    QString getOneTimePassword();
};

#endif // BANKACCOUNT_H
