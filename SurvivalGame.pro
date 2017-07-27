TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gameplay.cpp \
    gameobject.cpp \
    vector2.cpp \
    player.cpp \
    controller.cpp \
    map.cpp

HEADERS += \
    gameplay.h \
    gameobject.h \
    vector2.h \
    player.h \
    controller.h \
    map.h
