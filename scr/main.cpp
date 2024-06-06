#include "loginsignin.h"
#include <QApplication>
#include "user.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User users;
    users.setName("maryam");
    users.setFamily("mir");
    users.setNationalCode("1234567890");
    users.setAge(20);
    users.setUniqueUsername("msm.mir");
    users.setPassword("aaaa");
    users.addUser();
    LoginSignin b(users);
    b.show();
    return a.exec();
}
