#include "bankaccount.h"
#include <QString>

BankAccount::BankAccount();
void BankAccount::setBankType(BankType bankType) {
    this->bankType = bankType;
}
void BankAccount::setCardNumber(QString cardNumber) {
    this->cardNumber = cardNumber;
}
void BankAccount::setIbanNumber(QString ibanNumber) {
    this->ibanNumber = ibanNumber;
}
void BankAccount::setAccountNumber(QString accountNumber) {
    this->accountNumber = accountNumber;
}
void BankAccount::setCvv2(QString cvv2) {
    this->cvv2 = cvv2;
}
void BankAccount::setBalance(long long int balance) {
    this->balance = balance;
}
void BankAccount::setExpirationDate(QString expirationDate) {
    this->expirationDate = expirationDate;
}
void BankAccount::setFourDigitPassword(QString fourDigitPassword) {
    this->fourDigitPassword = fourDigitPassword;
}
void BankAccount::setFixedPassword(QString fixedPassword) {
    this->fixedPassword = fixedPassword;
}
void BankAccount::setOneTimePassword(QString oneTimePassword) {
    this->oneTimePassword = oneTimePassword;
}
BankType BankAccount::getBankType() {
    return this->bankType;
}
QString BankAccount::getCardNumber() {
    return this->cardNumber;
}
QString BankAccount::getIbanNumber() {
    return this->ibanNumber;
}
QString BankAccount::getAccountNumber() {
    return this->accountNumber;
}
QString BankAccount::getCvv2() {
    return this->cvv2;
}
long long int BankAccount::getBalance() {
    return this->balance;
}
QString BankAccount::getExpirationDate() {
    return this->expirationDate;
}
QString BankAccount::getFourDigitPassword() {
    return this->fourDigitPassword;
}
QString BankAccount::getFixedPassword() {
    return this->fixedPassword;
}
QString BankAccount::getOneTimePassword() {
    return this->oneTimePassword;
}
