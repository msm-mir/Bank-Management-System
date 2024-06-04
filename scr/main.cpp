#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "cardinfo.h"
#include "transfer.h"
#include "confirmtransfer.h"
#include "changepassword.h"
#include "viewbalance.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSignin b;
    b.show();
    return a.exec();
}
