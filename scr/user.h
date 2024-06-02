#ifndef USER_H
#define USER_H

#include <QString>
#include "bankaccount.h"

class User {
private:
    QString name;
    QString family;
    QString nationalCode;
    int age;
    QString uniqueUsername;
    QString password;
    BankAccount singleBankAccount;

public:
    User();
    void setName(QString);
    void setFamily(QString);
    void setNationalCode(QString);
    void setAge(int);
    void setUniqueUsername(QString);
    void setPassword(QString);
    void setSingleBankAccount(BankAccount);
    QString getName();
    QString getFamily();
    QString getNationalCode();
    int getAge();
    QString getUniqueUsername();
    QString getPassword();
    BankAccount getSingleBankAccount();
};

#endif // USER_H
