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

    layer = new Layer(this);
    layer->get_ui()->text_url->installEventFilter(this);

    this->installEventFilter(this);
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

void Browser::handler_view(int view_to_open, bool open)
{
    int cv = current_view;

    if ((col == 4) && (!open)) {
        col = 0;
        ++row;
    }

    ui->layout_main->removeWidget(views[cv]);
    if (open) {
        int i = layer->get_ui()->layout_miniatures->indexOf(views[view_to_open]);
        int r, c, rs, cs;
        layer->get_ui()->layout_miniatures->getItemPosition(i, &r, &c, &rs, &cs);
        layer->get_ui()->layout_miniatures->addWidget(views[cv], r, c);
    } else {
        layer->get_ui()->layout_miniatures->addWidget(views[cv], row, col);
    }
    //views[cv]->setMaximumSize(400, 250); // TODO: %
    views[cv]->setZoomFactor(0.40);
    views[cv]->get_ui()->button_miniature->setParent(views[cv]);
    views[cv]->get_ui()->button_miniature->show();
    connect(views[cv]->get_ui()->button_miniature, &ButtonMiniature::clicked, [=] {
        views[cv]->get_ui()->button_miniature->disconnect();
        handler_view(cv, true);
    });
    connect(views[cv]->get_ui()->button_miniature_close, &QPushButton::released, [=] {
        layer->get_ui()->layout_miniatures->removeWidget(views[cv]);
        delete views[cv];
        views[cv] = NULL;
    });

    if (open) {
        layer->get_ui()->layout_miniatures->removeWidget(views[view_to_open]);
        views[view_to_open]->get_ui()->button_miniature->hide();
        views[view_to_open]->get_ui()->button_miniature->setParent(NULL);
        //views[view_to_open]->setMaximumSize(1920, 1080); // TODO: %
        views[view_to_open]->setZoomFactor(1.0);
        ui->layout_main->insertWidget(0, views[view_to_open]);

        QUrl url = views[view_to_open]->url();
        layer->set_url(url);

        current_view = view_to_open;
        layer->set_visible(this);
    }

    ++col;
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        if (o == this) {
            switch(key->key()) {
                case Qt::Key_Left:
                    views[current_view]->back();
                    break;
                case Qt::Key_Right:
                    views[current_view]->forward();
                    break;
                case Qt::Key_Return:
                    views[current_view]->reload();
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
        } else if (o == layer->get_ui()->text_url) {
            switch(key->key()) {
                case Qt::Key_Return:
                    if (!layer->get_ui()->text_url->document()->toPlainText().simplified().isEmpty()) {
                        if ((key->modifiers() == Qt::ShiftModifier) || (view == NULL))
                            create_view();
                        url.setUrl(layer->get_ui()->text_url->document()->toPlainText().simplified());
                        views[current_view]->load_url(url);
                        layer->set_visible(this);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return QObject::eventFilter(o, e);
}
