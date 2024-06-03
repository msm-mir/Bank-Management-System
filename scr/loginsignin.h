#ifndef LOGINSIGNIN_H
#define LOGINSIGNIN_H

#include <QWidget>

namespace Ui {
class LoginSignin;
}

class LoginSignin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginSignin(QWidget *parent = nullptr);
    ~LoginSignin();

private:
    Ui::LoginSignin *ui;
};


#endif // LOGINSIGNIN_H
