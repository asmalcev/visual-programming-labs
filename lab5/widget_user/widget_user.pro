#-------------------------------------------------
#
# Project created by QtCreator 2022-01-19T14:18:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widget_user
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-graphic_control_panel-Desktop-Debug/release/ -lgraphic_control_panel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-graphic_control_panel-Desktop-Debug/debug/ -lgraphic_control_panel
else:unix: LIBS += -L$$PWD/../build-graphic_control_panel-Desktop-Debug/ -lgraphic_control_panel

INCLUDEPATH += $$PWD/../build-graphic_control_panel-Desktop-Debug
DEPENDPATH += $$PWD/../build-graphic_control_panel-Desktop-Debug
