#-------------------------------------------------
#
# Project created by QtCreator 2021-03-04T09:35:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = page_hello_world
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/qwt-6.1.2/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../../usr/local/qwt-6.1.2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/qwt-6.1.2/include

OTHER_FILES += \
    a.qss
