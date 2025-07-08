QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bankaccount.cpp \
    card.cpp \
    cardinfo.cpp \
    changepassword.cpp \
    confirmtransfer.cpp \
    createbankaccount.cpp \
    list.cpp \
    loginsignin.cpp \
    main.cpp \
    mainpanel.cpp \
    transfer.cpp \
    user.cpp \
    viewbalance.cpp

HEADERS += \
    bankaccount.h \
    card.h \
    cardinfo.h \
    changepassword.h \
    confirmtransfer.h \
    createbankaccount.h \
    list.h \
    loginsignin.h \
    mainpanel.h \
    transfer.h \
    user.h \
    viewbalance.h

FORMS += \
    cardinfo.ui \
    changepassword.ui \
    confirmtransfer.ui \
    createbankaccount.ui \
    loginsignin.ui \
    mainpanel.ui \
    transfer.ui \
    viewbalance.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Panel.qrc \
    loginsignup.qrc
