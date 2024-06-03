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
    ViewBalance i;
    i.show();
    ChangePassword h;
    h.show();
    ConfirmTransfer g;
    g.show();
    Transfer f;
    f.show();
    CardInfo e;
    e.show();
    CreateBankAccount d;
    d.show();
    MainPanel c;
    c.show();
    LoginSignin b;
    b.show();
    return a.exec();
}
