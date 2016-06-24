#include "view.h"

#include <QWebEngineSettings>

View::View(QWebEngineView *parent)
    : QWebEngineView(parent)
    , ui(new Ui::View)
{
    ui->setupUi();

    this->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, false);
    this->page()->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, false);
}

View::~View()
{
    delete ui;
}

void View::load_url(QUrl &url)
{
    if (url.isValid()) {
        if (url.scheme().isEmpty())
            url.setScheme("http");
//        qDebug() << url.scheme();
//        qDebug() << url.host();
//        qDebug() << url.path();
//        qDebug() << url.query();
        load(url);
    }
}
