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
void BankAccount::setBalance(long long int balance) {
    this->balance = balance;
}
void BankAccount::setBankCard(Card bankCard) {
    this->bankCard = bankCard;
}
void BankAccount::setLastTransferDate(tm lastTransferDate) {
    this->lastTransferDate = lastTransferDate;
}
void BankAccount::setLastTransferAmount(long long int transferAmount) {
    this->lastTransferAmount = transferAmount;
}
BankType BankAccount::getBankType() {
    return this->bankType;
}
QString BankAccount::getBankAccountNumber() {
    return this->bankAccountNum;
}
long long int BankAccount::getBalance() {
    return this->balance;
}
Card BankAccount::getBankCard() {
    return this->bankCard;
}
tm BankAccount::getLastTransferDate() {
    return this->lastTransferDate;
}
long long int BankAccount::getLastTransferAmount() {
    return this->lastTransferAmount;
}
