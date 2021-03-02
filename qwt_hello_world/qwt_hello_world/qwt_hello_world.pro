#-------------------------------------------------
#
# Project created by QtCreator 2021-02-28T19:06:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qwt_hello_world
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plotlines.cpp

HEADERS  += mainwindow.h \
    plotlines.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/qwt-6.1.2/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../usr/local/qwt-6.1.2/include
DEPENDPATH += $$PWD/../../../../../usr/local/qwt-6.1.2/include
