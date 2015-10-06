TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system


SOURCES += main.cpp \
    house_fabio.cc \
    Bombs.cc

HEADERS += \
    utils.hh \
    house_fabio.hh \
    Bombs.hh

