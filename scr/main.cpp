#include "loginsignin.h"
#include "mainpanel.h"
#include "createbankaccount.h"
#include "cardinfo.h"
#include "transfer.h"
#include "confirmtransfer.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSignin x;
    x.show();
    MainPanel b;
    b.show();
    CreateBankAccount c;
    c.show();
    CardInfo d;
    d.show();
    Transfer e;
    e.show();
    ConfirmTransfer f;
    f.show();
    return a.exec();
}
