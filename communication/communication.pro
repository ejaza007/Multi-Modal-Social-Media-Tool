TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += \
        chat.cpp \
        group_chat.cpp \
        main.cpp

HEADERS += \
    chat.h \
    group_chat.h
