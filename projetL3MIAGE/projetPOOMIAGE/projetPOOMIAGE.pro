TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    customer.cpp \
    buyer.cpp \
    visit.cpp \
    flat.cpp \
    house.cpp \
    plot.cpp

HEADERS += \
    customer.h \
    buyer.h \
    visit.h \
    flat.h \
    house.h \
    plot.h
