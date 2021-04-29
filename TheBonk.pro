QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brama.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    pies.cpp \
    pustak.cpp \
    selectlvl.cpp \
    tlo.cpp \
    wrog.cpp

HEADERS += \
    brama.h \
    mainwindow.h \
    menu.h \
    pies.h \
    pustak.h \
    selectlvl.h \
    tlo.h \
    wrog.h

FORMS += \
    mainwindow.ui \
    selectlvl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Stuff.qrc
