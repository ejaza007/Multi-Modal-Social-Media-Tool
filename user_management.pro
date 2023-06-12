TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

QT += core
QT += sql


SOURCES += \
        accountmanipulator.cpp \
        fish.cpp \
        main.cpp \
        user.cpp

HEADERS += \
    accountmanipulator.h \
    fish.h \
    user.h

FORMS +=
