#ifndef CREATEBANKACCOUNT_H
#define CREATEBANKACCOUNT_H

#include <QWidget>

namespace Ui {
class CreateBankAccount;
}

class CreateBankAccount : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBankAccount(QWidget *parent = nullptr);
    ~CreateBankAccount();

private:
    Ui::CreateBankAccount *ui;
};

#endif // CREATEBANKACCOUNT_H
