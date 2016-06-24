#include "browser.h"

Browser::Browser(QWidget *parent)
    : QWidget(parent)
    , view(NULL)
    , layer(NULL)
    , row(0)
    , col(0)
    , current(0)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);
    ui->mainLayout->insertWidget(1, ui->progressBar);

    this->installEventFilter(this);

    create_layer();
}

Browser::~Browser()
{
    for (uint i = 1; i <= views.size(); i++)
        if(views[i - 1] != NULL)
            delete views[i - 1];
    delete layer;
    delete ui;
}

void Browser::create_view()
{
    view = new View;
    QObject::connect(view, &View::loadStarted, [&] { ui->progressBar->show(); });
    QObject::connect(view, &View::loadProgress, [&] (int p) { ui->progressBar->setValue(p); });
    QObject::connect(view, &View::loadFinished, [&] { ui->progressBar->setValue(100); ui->progressBar->hide(); });
    QObject::connect(view, &View::renderProcessTerminated, [&]
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

    views.push_back(view);
    if (views.size() > 1)
        handler_view();

    ui->mainLayout->insertWidget(0, views.back());
    current = (views.size() - 1);
}

void Browser::create_layer()
{
    layer = new Layer;
    layer->setParent(this);
}

void Browser::handler_view(int offset, bool open)
{
    int c = current;
    if ((row == 5) && !open) {
        row = 0;
        ++col;
    }

    ui->mainLayout->removeWidget(views[c]);
    views[c]->setMaximumSize(400, 250); // TODO: %
    views[c]->setZoomFactor(0.40);
    layer->get_ui_object()->layoutMiniatures->addWidget(views[c], col, row, Qt::AlignLeft);
    views[c]->get_ui_object()->buttonMiniature->setParent(views[c]);
    views[c]->get_ui_object()->buttonMiniature->show();
    QObject::connect(views[c]->get_ui_object()->buttonMiniature, &ButtonMiniature::clicked, [=] {
        views[c]->get_ui_object()->buttonMiniature->disconnect();
        handler_view(c, true);
    });
    QObject::connect(views[c]->get_ui_object()->buttonMiniatureClose, &QPushButton::released, [=] {
        delete views[c];
        views[c] = NULL;
    });

    if (open) {
        views[offset]->get_ui_object()->buttonMiniature->hide();
        views[offset]->get_ui_object()->buttonMiniature->setParent(NULL);
        layer->get_ui_object()->layoutMiniatures->removeWidget(views[offset]);
        views[offset]->setMaximumSize(1920, 1080); // TODO: %
        views[offset]->setZoomFactor(1.0);
        ui->mainLayout->insertWidget(0, views[offset]);
        current = offset;
        handler_layer();
    }

    ++row;
}

void Browser::handler_layer()
{
    if (layer->isHidden()) {
        layer->setParent(NULL);
        layer->setParent(this);
        layer->setVisible(true);
        layer->get_ui_object()->lineEditUrl->setFocus();
    } else {
        layer->setHidden(true);
    }
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if ((o == this) && (e->type() == QEvent::KeyPress)) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        switch(key->key()) {
            case Qt::Key_Left:
                view->back();
                break;
            case Qt::Key_Right:
                view->forward();
                break;
            case Qt::Key_Return:
                if (layer->isVisible()) {
                    if ((key->modifiers() == Qt::ShiftModifier) || (view == NULL))
                        create_view();
                    url.setUrl(layer->get_ui_object()->lineEditUrl->text());
                    view->load_url(url);
                    handler_layer();
                } else {
                    view->reload();
                }
                break;
            case Qt::Key_Q:
                if (key->modifiers() == Qt::ControlModifier)
                    close();
                break;
            default:
                break;
        }
        if (key->modifiers() == Qt::MetaModifier)
            handler_layer();
    }
    return QObject::eventFilter(o, e);
}
