#-------------------------------------------------
#
# Project created by QtCreator 2015-06-08T19:14:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuKeyBoardTest
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DuKeyBoard.cpp \
    DuKeyPushButton.cpp

HEADERS  += Widget.h \
    DuKeyBoard.h \
    DuKeyPushButton.h

FORMS    += Widget.ui

RESOURCES += \
    virtualboard.qrc

QMAKE_CXXFLAGS += -std=gnu++14
