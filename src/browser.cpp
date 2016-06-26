#include "browser.h"

Browser::Browser(QWidget *parent)
    : QWidget(parent)
    , view(NULL)
    , layer(NULL)
    , row(0)
    , col(0)
    , current_view(0)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);

    this->installEventFilter(this);

    layer = new Layer(this);
}

Browser::~Browser()
{
    for (uint i = 1; i <= views.size(); i++)
        if (views[i - 1] != NULL)
            delete views[i - 1];
    delete layer;
    delete ui;
}

void Browser::create_view()
{
    view = new View(ui, layer);

    views.push_back(view);
    if (views.size() > 1)
        handler_view();

    current_view = (views.size() - 1);

    ui->layout_main->insertWidget(0, views.back());
}

void Browser::handler_view(int view_to_open)
{
    int cv = current_view;

    if ((row == 5) && (view_to_open != -1)) {
        row = 0;
        ++col;
    }

    ui->layout_main->removeWidget(views[cv]);
    layer->get_ui()->layout_miniatures->addWidget(views[cv], col, row, Qt::AlignLeft);
    views[cv]->setMaximumSize(400, 250); // TODO: %
    views[cv]->setZoomFactor(0.40);
    views[cv]->get_ui()->button_miniature->setParent(views[cv]);
    views[cv]->get_ui()->button_miniature->show();
    connect(views[cv]->get_ui()->button_miniature, &ButtonMiniature::clicked, [=] {
        views[cv]->get_ui()->button_miniature->disconnect();
        handler_view(cv);
    });
    connect(views[cv]->get_ui()->button_miniature_close, &QPushButton::released, [=] {
        delete views[cv];
        views[cv] = NULL;
    });

    if (view_to_open != -1) {
        layer->get_ui()->layout_miniatures->removeWidget(views[view_to_open]);
        views[view_to_open]->get_ui()->button_miniature->hide();
        views[view_to_open]->get_ui()->button_miniature->setParent(NULL);
        views[view_to_open]->setMaximumSize(1920, 1080); // TODO: %
        views[view_to_open]->setZoomFactor(1.0);
        ui->layout_main->insertWidget(0, views[view_to_open]);

        QUrl url = views[view_to_open]->url();
        layer->set_url(url);

        current_view = view_to_open;
        layer->set_visible(this);
    }

    ++row;
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if ((o == this) && (e->type() == QEvent::KeyPress)) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        switch(key->key()) {
            case Qt::Key_Left:
                views[current_view]->back();
                break;
            case Qt::Key_Right:
                views[current_view]->forward();
                break;
            case Qt::Key_Return:
                if (layer->isVisible()) {
                    if ((key->modifiers() == Qt::ShiftModifier) || (view == NULL))
                        create_view();
                    url.setUrl(layer->get_ui()->lineedit_url->text());
                    views[current_view]->load_url(url);
                    layer->set_visible(this);
                } else {
                    views[current_view]->reload();
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
            layer->set_visible(this);
    }
    return QObject::eventFilter(o, e);
}
