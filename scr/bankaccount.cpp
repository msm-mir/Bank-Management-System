#include "bankaccount.h"
#include <QString>

BankAccount::BankAccount() {}
BankAccount::~BankAccount() {}

void BankAccount::setBankType(BankType bankType) {
    this->bankType = bankType;
}
void BankAccount::setBankAccountNumber(QString accountNumber) {
    this->bankAccountNum = accountNumber;
}
void BankAccount::setBalance(QString balance) {
    this->balance = balance;
}
void BankAccount::setBankCard(Card bankCard) {
    this->bankCard = bankCard;
}
BankType BankAccount::getBankType() {
    return this->bankType;
}
QString BankAccount::getBankAccountNumber() {
    return this->bankAccountNum;
}
QString BankAccount::getBalance() {
    return this->balance;
}
Card BankAccount::getBankCard() {
    return this->bankCard;
}
