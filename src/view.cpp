#include "view.h"

#include <QWebEngineSettings>

View::View(Ui::Browser *ui_browser, Layer *layer, QWebEngineView *parent)
    : QWebEngineView(parent)
    , update_layer_text_url(true)
    , ui(new Ui::View)
{
    ui->setupUi();

    this->setPage(&webpage);
    this->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, false);
    this->page()->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, false);

    connect(this, &QWebEngineView::loadStarted, [=] { ui_browser->progressbar->show(); });
    connect(this, &QWebEngineView::loadProgress, [=] (int p) { ui_browser->progressbar->setValue(p); });
    connect(this, &QWebEngineView::loadFinished, [=] { ui_browser->progressbar->hide(); });
    connect(this, &QWebEngineView::urlChanged, [=] (QUrl url) {
        if (update_layer_text_url)
            layer->set_url(url);
    });
    connect(&this->webpage, &WebPage::link_clicked, [&] (QUrl url) { emit link_clicked(url); });
}

View::~View()
{
    delete ui;
}

void View::load_url(QUrl &url, bool update)
{
    update_layer_text_url = update;

    if (url.isValid()) {
        if (url.scheme().isEmpty())
            url.setScheme("http");
        load(url);
    }
}

/*
    connect(this, &QWebEngineView::renderProcessTerminated, [=]
           (QWebEnginePage::RenderProcessTerminationStatus termStatus, int statusCode) {
        switch (termStatus) {
            case QWebEnginePage::NormalTerminationStatus:
                qDebug() << "Render process normal exit" << "CODE: " << statusCode;
                break;
            case QWebEnginePage::AbnormalTerminationStatus:
                qDebug() << "Render process abnormal exit" << "CODE: " << statusCode;
                break;
            case QWebEnginePage::CrashedTerminationStatus:
                qDebug() << "Render process crashed" << "CODE: " << statusCode;
                break;
            case QWebEnginePage::KilledTerminationStatus:
                qDebug() << "Render process killed" << "CODE: " << statusCode;
                break;
            default:
                break;
        }
    });
*/
