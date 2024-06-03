#ifndef CONFIRMTRANSFER_H
#define CONFIRMTRANSFER_H

#include <QWidget>

namespace Ui {
class ConfirmTransfer;
}

class ConfirmTransfer : public QWidget
{
    Q_OBJECT

public:
    explicit ConfirmTransfer(QWidget *parent = nullptr);
    ~ConfirmTransfer();

private:
    Ui::ConfirmTransfer *ui;
};

#endif // CONFIRMTRANSFER_H
