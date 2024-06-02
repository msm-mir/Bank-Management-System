#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QString>

class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    void setName(QString name);
    QString getName();
    void setFamily(QString family);
    QString getFamily();
    void setNationalCode(QString nationalCode);
    QString getNationalCode();
    void setAge(int age);
    int getAge();
    void setUniqueUsername(QString uniqueUsername);
    QString getUniqueUsername();
    void setPassword(QString password);
    QString getPassword();
    void setSingleBankAccount(QString singleBankAccount);
    QString getSingleBankAccount();

signals:

private:
    QString name;
    QString family;
    QString nationalCode;
    int age;
    QString uniqueUsername;
    QString password;
    QString singleBankAccount;
};

#endif // USER_H
