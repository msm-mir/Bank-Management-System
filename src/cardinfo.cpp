#include "cardinfo.h"
#include "ui_cardinfo.h"
#include "user.h"
#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "changepassword.h"
#include "viewbalance.h"
#include "transfer.h"

#include <bits/stdc++.h>
#include <ctime>
#include <QKeyEvent>

using namespace std;

CardInfo::CardInfo(User users, QWidget *parent) : QWidget(parent) , ui(new Ui::CardInfo) {
    ui->setupUi(this);

    //disable maximize
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    //set user
    this->users = users;

    initialUserSet();

    addInfo();

    //create card info
    createCardInfo();

    //click to open pages
    connect(ui->createNewBankAccountPB, SIGNAL(clicked()), this, SLOT(openCreateBankAccountPage()));
    connect(ui->changePasswordPB, SIGNAL(clicked()), this, SLOT(openChangePasswordPage()));
    connect(ui->viewBalancePB, SIGNAL(clicked()), this, SLOT(openViewBalancePage()));
    connect(ui->transferPB, SIGNAL(clicked()), this, SLOT(openTransferPage()));

    //click done push button
    connect(ui->donePB, SIGNAL(clicked()), this, SLOT(openMainPanelPage()));

    //click logout push button
    connect(ui->logoutPB, SIGNAL(clicked()), this, SLOT(openLogoutPage()));
}
CardInfo::~CardInfo() {
    delete ui;
}

void CardInfo::addInfo() {
    ui->firstNameST->setText(users.getName());
    ui->lastNameST->setText(users.getFamily());
    ui->nationalCodeST->setText(users.getNationalCode());
    ui->ageST->setText(QString::number(users.getAge()));
}

void CardInfo::createCardInfo() {
    createCardNumber();
    createAccountNumber();
    createCardCvv2();
    createCardExpirationDate();

    finalUserSet();
}

//shuffle national code digits
void CardInfo::createCardNumber() {
    string cardNumber = "603799";
    string nationalCode = users.getNationalCode().toStdString();

    srand(time(0));
    random_shuffle(nationalCode.begin(), nationalCode.end());

    cardNumber += nationalCode;

    ui->cardNumberST->setText(QString::fromStdString(cardNumber));
}

void CardInfo::createAccountNumber() {
    srand(time(0));

    string accountNumber = "00112233445566778899";
    random_shuffle(accountNumber.begin(), accountNumber.end());

    for (int i = 0; i < 7; i++)
        accountNumber.pop_back();

    ui->accountNumberST->setText(QString::fromStdString(accountNumber));
    createCardIbanNumber(accountNumber);
}

void CardInfo::createCardIbanNumber(string accountNumber) {
    string ibanNumber = "IR98018";

    BankAccount tmpBank = users.getSingleBankAccount(users.getBankAccountNum() - 1);

    ibanNumber += tmpBank.getBankType() + 48;
    ibanNumber += "000000";
    ibanNumber += accountNumber;

    ui->ibanNumberST->setText(QString::fromStdString(ibanNumber));
}

void CardInfo::createCardCvv2() {
    string cvv2 = "0123456789";

    srand(time(0));
    random_shuffle(cvv2.begin(), cvv2.end());

    for (int i = 0; i < 6; i++)
        cvv2.pop_back();

    ui->cvv2ST->setText(QString::fromStdString(cvv2));
}

void CardInfo::createCardExpirationDate() {
    tm futureDate = calculateFutureDate(3);
    QString expirationDate = "";

    expirationDate += QString::number(getYear(futureDate));
    expirationDate += '/';
    expirationDate += QString::number(getMonth(futureDate));

    ui->expirationDateST->setText(expirationDate);

    expirationDate += '/';
    expirationDate += QString::number(getDay(futureDate));

    cards.setExpirationDate(futureDate);
}

void CardInfo::openCreateBankAccountPage() {
    CreateBankAccount *np = new CreateBankAccount(users);
    np->show();
    this->close();
}

void CardInfo::openChangePasswordPage() {
    ChangePassword *np = new ChangePassword(users);
    np->show();
    this->close();
}

void CardInfo::openViewBalancePage() {
    ViewBalance *np = new ViewBalance(users);
    np->show();
    this->close();
}

void CardInfo::openTransferPage() {
    Transfer *np = new Transfer(users);
    np->show();
    this->close();
}

void CardInfo::openMainPanelPage() {
    MainPanel *np = new MainPanel(users);
    np->show();
    this->close();
}

void CardInfo::openLogoutPage() {
    LoginSignin *np = new LoginSignin(users);
    np->show();
    this->close();
}

tm CardInfo::getCurrentTime() {
    time_t now = time(nullptr);
    return *localtime(&now);
}

tm CardInfo::calculateFutureDate(int years) {
    tm currentDate = getCurrentTime();
    currentDate.tm_year += years;
    mktime(&currentDate);
    return currentDate;
}

int CardInfo::getYear(const tm& date) {
    return date.tm_year + 1900;
}

int CardInfo::getMonth(const tm& date) {
    return date.tm_mon + 1;
}

int CardInfo::getDay(const tm& date) {
    return date.tm_mday;
}

void CardInfo::initialUserSet() {
    //set bank account
    this->bankAccounts = users.getSingleBankAccount(users.getBankAccountNum() - 1);

    //set card
    this->cards = users.getSingleBankAccount(users.getBankAccountNum() - 1).getBankCard();
}

void CardInfo::finalUserSet() {
    //set to card
    cards.setCardNumber(ui->cardNumberST->text());
    cards.setIbanNumber(ui->ibanNumberST->text());
    cards.setCvv2(ui->cvv2ST->text());

    //set to bank account
    bankAccounts.setBankAccountNumber(ui->accountNumberST->text());

    //set to user
    bankAccounts.setBankCard(cards);
    users.setSingleBankAccount(bankAccounts, users.getBankAccountNum() - 1);

    //set to list of users
    users.updateUserDataInList(users.getNationalCode());
}

void CardInfo::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        ui->donePB->click();
    }
    else {
        QWidget::keyPressEvent(event);
    }
}
