#include "user.h"
#include "list.h"
#include "bankaccount.h"
#include <QString>
#include <ctime>

using namespace std;

User::User() {}
User::~User() {}

//setter
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

//getter
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

//add user to link list in sign up page
void User::addUser() {
    listUsers.pushBack(*this);
}

//find user for log in page
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

//is name unique for sign up
bool User::uniqueName(QString name) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getName() == name)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

//is family unique for sign up
bool User::uniqueFamily(QString family) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getFamily() == family)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

//is national code unique for sign up
bool User::uniqueNationalCode(QString nationalCode) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getNationalCode() == nationalCode)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

//is username unique for sign up
bool User::uniqueUsername(QString username) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUniqueUsername() == username)
            return true;
        tmp = tmp->getNextNode();
    }
    return false;
}

//set user information in log in for other pages
void User::setUserInfo(QString username) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUniqueUsername() == username) {
            this->setName(tmp->getData().getName());
            this->setFamily(tmp->getData().getFamily());
            this->setNationalCode(tmp->getData().getNationalCode());
            this->setAge(tmp->getData().getAge());
            this->setUniqueUsername(tmp->getData().getUniqueUsername());
            this->setPassword(tmp->getData().getPassword());

            BankAccount bankAccount;
            for (int i = 0; i < this->getBankAccountNum(); i++) {
                this->setSingleBankAccount(bankAccount, i);
            }

            for (int i = 0; i < tmp->getData().getBankAccountNum(); i++)
                this->setSingleBankAccount(tmp->getData().getSingleBankAccount(i), i);

            this->setBankAccountNum(tmp->getData().getBankAccountNum());

            return;
        }
        tmp = tmp->getNextNode();
    }
}

//set user's new information to link list
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

//search destination card number for transfer page
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

//is destination bank card expired for transfer
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

int User::findDestiUserIdx(QString cardNumber) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        for (int i = 0; i < tmp->getData().getBankAccountNum(); i++) {
            if (tmp->getData().getSingleBankAccount(i).getBankCard().getCardNumber() == cardNumber) {
                return i;
            }
        }
        tmp = tmp->getNextNode();
    }
}

User User::findDestiUser(QString cardNumber) {
    Node<User> *tmp = listUsers.getHeadNode();
    while (tmp) {
        for (int i = 0; i < tmp->getData().getBankAccountNum(); i++) {
            if (tmp->getData().getSingleBankAccount(i).getBankCard().getCardNumber() == cardNumber) {
                return tmp->getData();
            }
        }
        tmp = tmp->getNextNode();
    }
}
