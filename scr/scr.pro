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
    createbankaccount.cpp \
    list.cpp \
    loginsignin.cpp \
    main.cpp \
    mainpanel.cpp \
    user.cpp

HEADERS += \
    bankaccount.h \
    card.h \
    cardinfo.h \
    createbankaccount.h \
    list.h \
    loginsignin.h \
    mainpanel.h \
    user.h

FORMS += \
    cardinfo.ui \
    createbankaccount.ui \
    loginsignin.ui \
    mainpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Panel.qrc \
    loginsignup.qrc
