TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    hal.c \
    ../../common/behavior.c

HEADERS += \
    ../../common/datatypes.h \
    ../../common/hal.h \
    ../../common/behavior.h
