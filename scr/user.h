#ifndef USER_H
#define USER_H

#include <QString>
#include "bankaccount.h"
#include "list.h"

class User {
private:
    QString name;
    QString family;
    QString nationalCode;
    int age;
    QString username;
    QString password;
    BankAccount singleBankAccount[5];
    int bankAccountNum;
public:
    List<User> listUsers;

    User();
    ~User();

    void setName(QString);
    void setFamily(QString);
    void setNationalCode(QString);
    void setAge(int);
    void setUniqueUsername(QString);
    void setPassword(QString);
    void setSingleBankAccount(BankAccount, int);
    void setBankAccountNum(int);

    QString getName();
    QString getFamily();
    QString getNationalCode();
    int getAge();
    QString getUniqueUsername();
    QString getPassword();
    BankAccount getSingleBankAccount(int);
    int getBankAccountNum();

    void addUser();
    QString find(QString, QString);
    bool uniqueName(QString);
    bool uniqueFamily(QString);
    bool uniqueNationalCode(QString);
    bool uniqueUsername(QString);
    void setUserInfo(QString, QString);
};

#endif // USER_H
