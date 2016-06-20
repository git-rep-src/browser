#include "browser.h"

Browser::Browser(QWidget *parent)
    : QWidget(parent)
    , view(NULL)
    , layer(NULL)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);
    this->installEventFilter(this);

    init_view();
    vectorViews[0]->load_url("lamiradadelreplicante.com");
    ui->layoutMain->addWidget(ui->progressBar);

    init_layer();
}

Browser::~Browser()
{
    for (uint i = 1; i <= vectorViews.size(); i++)
        delete vectorViews[i - 1];
    delete layer;
    delete ui;
}

void Browser::init_view()
{
    view = new View;
    QObject::connect(view, &View::loadStarted, [&] { ui->progressBar->show(); });
    QObject::connect(view, &View::loadProgress, [&] (int p){ ui->progressBar->setValue(p); });
    QObject::connect(view, &View::loadFinished, [&] { ui->progressBar->hide(); });

    vectorViews.push_back(view);
    if (vectorViews.size() > 1) {
        for (uint i = 1; i < vectorViews.size(); i++) {
            vectorViews[i - 1]->setMaximumSize(400, 300); // TODO: %
            vectorViews[i - 1]->setZoomFactor(0.40);
            layer->get_ui_object()->gridLayout->addWidget(vectorViews[i -1], 0, i, Qt::AlignTop | Qt::AlignLeft);
        }
    }

    ui->layoutMain->insertWidget(0, vectorViews.back());
}

void Browser::init_layer()
{
    layer = new Layer;
    layer->setParent(this);
}

void Browser::show_layer()
{
    if (layer->isHidden()) {
        if (vectorViews.size() > 1)
            layer->get_ui_object()->widgetDarkLayer->show();
        else
            layer->get_ui_object()->widgetDarkLayer->hide();
        layer->setParent(NULL);
        layer->setParent(this);
        layer->setVisible(true);
        layer->get_ui_object()->lineEditUrl->setFocus();
    } else {
        layer->setHidden(true);
    }
}

bool Browser::eventFilter(QObject *obj, QEvent *event)
{
    if ((obj == this) && (event->type() == QEvent::KeyPress)) {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);
        switch(key->key()) {
            case Qt::Key_Left:
                view->back();
                break;
            case Qt::Key_Right:
                view->forward();
                break;
            case Qt::Key_Return:
                if (layer->isVisible()) {
                    if (key->modifiers() == Qt::ShiftModifier)
                        init_view();
                    view->load_url(layer->get_ui_object()->lineEditUrl->text());
                    show_layer();
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
            show_layer();
    }
    return QObject::eventFilter(obj, event);
}
