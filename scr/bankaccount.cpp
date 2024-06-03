#include "bankaccount.h"
#include <QString>

BankAccount::BankAccount() {}
void BankAccount::setBankType(BankType bankType) {
    this->bankType = bankType;
}
void BankAccount::setAccountNumber(QString accountNumber) {
    this->accountNumber = accountNumber;
}
void BankAccount::setBalance(long long int balance) {
    this->balance = balance;
}
void BankAccount::setBankCard(Card bankCard) {
    this->bankCard = bankCard;
}
BankType BankAccount::getBankType() {
    return this->bankType;
}
QString BankAccount::getAccountNumber() {
    return this->accountNumber;
}
long long int BankAccount::getBalance() {
    return this->balance;
}
Card BankAccount::getBankCard() {
    return this->bankCard;
}
