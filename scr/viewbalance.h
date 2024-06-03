#ifndef VIEWBALANCE_H
#define VIEWBALANCE_H

#include <QWidget>

namespace Ui {
class ViewBalance;
}

class ViewBalance : public QWidget
{
    Q_OBJECT

public:
    explicit ViewBalance(QWidget *parent = nullptr);
    ~ViewBalance();

private:
    Ui::ViewBalance *ui;
};

#endif // VIEWBALANCE_H
