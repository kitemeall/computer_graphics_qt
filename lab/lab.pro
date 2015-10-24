#-------------------------------------------------
#
# Project created by QtCreator 2015-09-27T20:46:40
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    point.cpp \
    triangle.cpp \
    line.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    point.h \
    triangle.h \
    line.h

FORMS    += mainwindow.ui
