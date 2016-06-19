QT += core gui webenginewidgets

TARGET = browser
TEMPLATE = app

SOURCES += src/main.cpp \
           src/browser.cpp \
           src/view.cpp \
           src/layer.cpp

HEADERS  += src/browser.h \
            src/view.h \
            src/layer.h \
            src/ui.h

RESOURCES = resources.qrc

RC_FILE = resources/images/global/icon.rc
