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
    explicit MainPanel(User, QWidget *parent = nullptr);
    ~MainPanel();

};

#endif // MAINPANEL_H
