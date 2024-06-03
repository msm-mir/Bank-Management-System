#ifndef CARDINFO_H
#define CARDINFO_H

#include <QWidget>

namespace Ui {
class CardInfo;
}

class CardInfo : public QWidget
{
    Q_OBJECT

public:
    explicit CardInfo(QWidget *parent = nullptr);
    ~CardInfo();

private:
    Ui::CardInfo *ui;
};

#endif // CARDINFO_H
