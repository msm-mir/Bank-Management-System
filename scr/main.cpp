#include "loginsignin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSignin b;
    b.show();
    return a.exec();
}
