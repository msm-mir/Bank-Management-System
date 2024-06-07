#include "user.h"
#include "list.h"
#include "bankaccount.h"
#include <QString>
#include <ctime>

using namespace std;

User::User() {}
User::~User() {}
void User::setName(QString name) {
    this->name = name;
}
void User::setFamily(QString family) {
    this->family = family;
}
void User::setNationalCode(QString nationalCode) {
    this->nationalCode = nationalCode;
}
void User::setAge(int age) {
    this->age = age;
}
void User::setUniqueUsername(QString uniqueUsername) {
    this->username = uniqueUsername;
}
void User::setPassword(QString password) {
    this->password = password;
}
void User::setSingleBankAccount(BankAccount singleBankAccount, int idx) {
    this->singleBankAccount[idx] = singleBankAccount;
}
void User::setBankAccountNum(int bankAccountNum) {
    this->bankAccountNum = bankAccountNum;
}
QString User::getName() {
    return this->name;
}
QString User::getFamily() {
    return this->family;
}
QString User::getNationalCode() {
    return this->nationalCode;
}
int User::getAge() {
    return this->age;
}
QString User::getUniqueUsername() {
    return this->username;
}
QString User::getPassword() {
    return this->password;
}
BankAccount User::getSingleBankAccount(int idx) {
    return this->singleBankAccount[idx];
}
int User::getBankAccountNum() {
    return this->bankAccountNum;
}

void User::addUser() {
    listUsers.pushBack(*this);
}

QString User::loginFind(QString username, QString password) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUniqueUsername() == username) {
            if (tmp->getData().getPassword() == password)
                return "true";
            return "incorrect password";
        }
        tmp = tmp->getNextNode();
    }
    return "non-existence of username";
}

bool User::uniqueName(QString name) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getName() == name)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

bool User::uniqueFamily(QString family) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getFamily() == family)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

bool User::uniqueNationalCode(QString nationalCode) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getNationalCode() == nationalCode)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

bool User::uniqueUsername(QString username) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUniqueUsername() == username)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

void User::setUserInfo(QString username, QString password) {
    this->setUniqueUsername(username);
    this->setPassword(password);

    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUniqueUsername() == username)
            if (tmp->getData().getPassword() == password) {
                this->setName(tmp->getData().getName());
                this->setFamily(tmp->getData().getFamily());
                this->setNationalCode(tmp->getData().getNationalCode());
                this->setAge(tmp->getData().getAge());
                return;
            }
        tmp = tmp->getNextNode();
    }
}

void User::updateUserDataInList(QString nationalCode) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getNationalCode() == nationalCode) {
            tmp->setData(*this);
            return;
        }
        tmp = tmp->getNextNode();
    }
}

bool User::findCardNumber(QString cardNumber) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        for (int i = 0; i < tmp->getData().getBankAccountNum(); i++) {
            if (tmp->getData().getSingleBankAccount(i).getBankCard().getCardNumber() == cardNumber)
                return false;
        }
        tmp = tmp->getNextNode();
    }
    return true;
}

bool User::checkDestiExpire(QString cardNumber) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        for (int i = 0; i < tmp->getData().getBankAccountNum(); i++) {
            if (tmp->getData().getSingleBankAccount(i).getBankCard().getCardNumber() == cardNumber) {
                tm expirationDate = tmp->getData().getSingleBankAccount(i).getBankCard().getExpirationDate();

                if (isBeforeNow(expirationDate)) {
                    return true;
                }

                return false;
            }
        }
        tmp = tmp->getNextNode();
    }
    return true;
}

bool User::isBeforeNow(const tm& date) {
    time_t now = time(nullptr);
    time_t inputTime = mktime(const_cast<tm*>(&date));
    return inputTime < now;
}
