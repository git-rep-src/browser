#include "view.h"

#include <QWebEngineSettings>

View::View(QWebEngineView *parent)
    : QWebEngineView(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    this->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, false);
    this->page()->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, false);
}

View::~View()
{
    delete ui;
}

void View::load_url(QString url)
{
    load(QUrl("http://"+url));
}
