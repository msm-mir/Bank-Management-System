#ifndef LOGINSIGNUP_H
#define LOGINSIGNUP_H

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


#endif // LOGINSIGNUP_H
