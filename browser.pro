QT += core gui webenginewidgets

TARGET = browser
TEMPLATE = app

SOURCES += src/main.cc \
           src/browser.cc \
           src/view.cc \
           src/layer.cc \
           src/tabbutton.cc

HEADERS  += src/browser.h \
            src/view.h \
            src/layer.h \
            src/ui.h \
            src/tabbutton.h

RESOURCES = resources.qrc

RC_FILE = resources/images/global/icon.rc

OBJECTS_DIR = .build/.obj
MOC_DIR = .build/.moc
RCC_DIR = .build/.rcc
