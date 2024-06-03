#include "user.h"
#include "bankaccount.h"
#include <QString>

User::User() {}
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
    this->uniqueUsername = uniqueUsername;
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
    return this->uniqueUsername;
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
