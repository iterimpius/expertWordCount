#-------------------------------------------------
#
# Project created by QtCreator 2013-01-24T05:25:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = expertWordCount
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    uniqueword.cpp \
    jobsettings.cpp \
    worker.cpp \
    jobui.cpp \
    settingsform.cpp

HEADERS  += widget.h \
    uniqueword.h \
    jobsettings.h \
    worker.h \
    jobui.h \
    settingsform.h

FORMS    += widget.ui \
    jobui.ui \
    settingsform.ui

RESOURCES += \
    res.qrc
