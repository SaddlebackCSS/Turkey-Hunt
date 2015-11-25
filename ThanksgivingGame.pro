#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T18:13:13
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThanksgivingGame
TEMPLATE = app


SOURCES += main.cpp\
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    health.h

FORMS    += \
    gamescreen.ui

RESOURCES += \
    res.qrc
