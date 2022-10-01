TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    pp/hal.c \
    ../pp/hal.c \
    hal.c \
    ../../common/behavior.c

HEADERS += \
    ../../common/data_types.h \
    ../common/hal.h \
    ../../common/hal.h \
    ../../common/behavior.h
