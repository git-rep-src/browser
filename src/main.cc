#include "browser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Browser browser;
    browser.showFullScreen();

    return a.exec();
}
