#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T20:19:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editdialog.cpp \
    createdialog.cpp \
    extinfo.cpp \
    ext2.cpp \
    advancedselect.cpp

HEADERS  += mainwindow.h \
    editdialog.h \
    createdialog.h \
    extinfo.h \
    ext2.h \
    advancedselect.h

FORMS    += mainwindow.ui \
    editdialog.ui \
    createdialog.ui \
    extinfo.ui \
    ext2.ui \
    advancedselect.ui
