#include "loginsignin.h"
#include <QApplication>
#include "user.h"
#include "card.h"
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User users;
    LoginSignin b(users);
    b.show();
    return a.exec();
}
