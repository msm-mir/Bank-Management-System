#include "loginsignin.h"
#include "mainpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSignin w;
    // w.show();
    MainPanel m;
    m.show();
    return a.exec();
}
