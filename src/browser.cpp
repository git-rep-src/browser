#include "browser.h"

Browser::Browser(QWidget *parent)
    : QWidget(parent)
    , pView(NULL)
    , pLayer(NULL)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);

    this->installEventFilter(this);

    view();
    vectorView[0]->load_url("lamiradadelreplicante.com");
    ui->mainLayout->addWidget(ui->progressBar);

    layer();
}

Browser::~Browser()
{
    for (uint i = 1; i <= vectorView.size(); i++)
        delete vectorView[i - 1];
    delete pLayer;
    delete ui;
}

void Browser::view()
{
    pView = new View;
    QObject::connect(pView, &View::loadStarted, [&] { ui->progressBar->show(); });
    QObject::connect(pView, &View::loadProgress, [&] (int p) { ui->progressBar->setValue(p); });
    QObject::connect(pView, &View::loadFinished, [&] { ui->progressBar->hide(); });

    vectorView.push_back(pView);
    if (vectorView.size() > 1)
        miniature_handler();

    ui->mainLayout->insertWidget(0, vectorView.back());
    currentView = (vectorView.size() - 1);
}

void Browser::layer()
{
    pLayer = new Layer;
    pLayer->setParent(this);
}

void Browser::layer_handle()
{
    if (pLayer->isHidden()) {
        pLayer->setParent(NULL);
        pLayer->setParent(this);
        pLayer->setVisible(true);
        pLayer->get_ui_object()->lineEditUrl->setFocus();
    } else {
        pLayer->setHidden(true);
    }
}

void Browser::miniature_handler(int min, bool open)
{
    int vv = currentView;
    if ((row == 5) && !open) {
        row = 0;
        ++col;
    }

    ui->mainLayout->removeWidget(vectorView[vv]);
    vectorView[vv]->setMaximumSize(400, 250); // TODO: %
    vectorView[vv]->setZoomFactor(0.40);
    pLayer->get_ui_object()->layoutMiniatures->addWidget(vectorView[vv], col, row, Qt::AlignTop | Qt::AlignLeft);
    vectorView[vv]->get_ui_object()->buttonMiniature->setParent(vectorView[vv]);
    vectorView[vv]->get_ui_object()->buttonMiniature->show();
    QObject::connect(vectorView[vv]->get_ui_object()->buttonMiniature, &ButtonMiniature::clicked, [=] {
        vectorView[vv]->get_ui_object()->buttonMiniature->disconnect();
        miniature_handler(vv, true);
    });

    if (open) {
        vectorView[min]->get_ui_object()->buttonMiniature->hide();
        vectorView[min]->get_ui_object()->buttonMiniature->setParent(NULL);
        pLayer->get_ui_object()->layoutMiniatures->removeWidget(vectorView[min]);
        vectorView[min]->setMaximumSize(1920, 1080); // TODO: %
        vectorView[min]->setZoomFactor(1.0);
        ui->mainLayout->insertWidget(0, vectorView[min]);
        currentView = min;
        layer_handle();
    }

    ++row;
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if ((o == this) && (e->type() == QEvent::KeyPress)) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        switch(key->key()) {
            case Qt::Key_Left:
                pView->back();
                break;
            case Qt::Key_Right:
                pView->forward();
                break;
            case Qt::Key_Return:
                if (pLayer->isVisible()) {
                    if (key->modifiers() == Qt::ShiftModifier)
                        view();
                    pView->load_url(pLayer->get_ui_object()->lineEditUrl->text());
                    layer_handle();
                } else {
                    pView->reload();
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
            layer_handle();
    }
    return QObject::eventFilter(o, e);
}
