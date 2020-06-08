include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_zeugnis.h

SOURCES += \
        main.cpp

DISTFILES += \
    doc/api-4-Zeugnis.adoc \
    doc/changelog.adoc
