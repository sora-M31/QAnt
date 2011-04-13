QT += opengl\
    += gui
INCLUDEPATH += include/
        += ui
OBJECTS_DIR = obj/
MOC_DIR = moc/
UI_HEADERS_DIR = ui/
TARGET = bin/test
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    include/mainwindow.h \
    ui/ui_mainwindow.h

FORMS += \
    ui/mainwindow.ui
