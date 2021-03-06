#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T21:37:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDP
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


SOURCES += main.cpp\
    mainwindow.cpp \
    scene.cpp \
    view.cpp \
    shapes/shape.cpp \
    shapes/block.cpp \
    shapes/ifblock.cpp \
    shapes/entrance.cpp \
    shapes/exit.cpp \
    shapes/bar.cpp \
    shapes/arrow.cpp \
    diagram.cpp \
    dialog.cpp \
    selectparametersdialog.cpp
    arrowposition.cpp
HEADERS  += mainwindow.h \
    scene.h \
    view.h \
    shapes/shape.h \
    shapes/block.h \
    shapes/ifblock.h \
    shapes/entrance.h \
    shapes/exit.h \
    shapes/bar.h \
    shapes/arrow.h \
    diagram.h \
    allocator/allocator.h \
    diagram_exception.h \
    dialog.h \
    selectparametersdialog.h
FORMS += mainwindow.ui \
    dialog.ui \
    selectparametersdialog.ui
    arrowposition.h
FORMS += mainwindow.ui
