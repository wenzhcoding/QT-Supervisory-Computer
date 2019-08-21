#-------------------------------------------------
#
# Project created by QtCreator 2017-10-17T16:32:30
#
#-------------------------------------------------

QT       += core gui
QT       +=serialport
QT       +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Em
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    qcw_indicatorlamp.cpp \
    widget.cpp \
    shuoming.cpp \
    dayin.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    qcw_indicatorlamp.h \
    widget.h \
    shuoming.h \
    dayin.h

FORMS += \
        mainwindow.ui \
    widget.ui \
    dayin.ui \
    shuoming.ui

win32: LIBS += -L$$PWD/./ -lWinIo

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
