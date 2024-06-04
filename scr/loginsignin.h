#ifndef LOGINSIGNIN_H
#define LOGINSIGNIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginSignin;
}
QT_END_NAMESPACE

class LoginSignin : public QWidget { Q_OBJECT

private:
    Ui::LoginSignin *ui;
public:
    explicit LoginSignin(QWidget *parent = nullptr);
    ~LoginSignin();
};

#endif // LOGINSIGNIN_H
