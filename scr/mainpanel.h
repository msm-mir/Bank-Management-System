#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QWidget>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainPanel;
}
QT_END_NAMESPACE

class MainPanel : public QWidget { Q_OBJECT

private:
    Ui::MainPanel *ui;
private slots:
public:
    User user;

    explicit MainPanel(User, QWidget *parent = nullptr);
    ~MainPanel();

    void addInfo();
    void openCreateBankAccountPage();
    void openChangePasswordPage();
    void openViewBalancePage();
    void openTransferPage();
    void logoutPBClick();
};

#endif // MAINPANEL_H
