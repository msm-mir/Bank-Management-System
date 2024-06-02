#include "user.h"
#include <QString>

User::User(QWidget *parent) : QWidget{parent} {}
void User::setName(QString name) {
    this->name = name;
}
QString User::getName() {
    return this->name;
}
void User::setFamily(QString family) {
    this->family = family;
}
QString User::getFamily() {
    return this->family;
}
void User::setNationalCode(QString nationalCode) {
    this->nationalCode = nationalCode;
}
QString User::getNationalCode() {
    return this->nationalCode;
}
void User::setAge(int age) {
    this->age = age;
}
int User::getAge() {
    return this->age;
}
void User::setUniqueUsername(QString uniqueUsername) {
    this->uniqueUsername = uniqueUsername;
}
QString User::getUniqueUsername() {
    return this->uniqueUsername;
}
void User::setPassword(QString password) {
    this->password = password;
}
QString User::getPassword() {
    return this->password;
}
void User::setSingleBankAccount(QString singleBankAccount) {
    this->singleBankAccount = singleBankAccount;
}
QString User::getSingleBankAccount() {
    return this->singleBankAccount;
}
