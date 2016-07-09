#include "layer.h"

Layer::Layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Layer)
{
    ui->setupUi(this);

    connect(ui->te_url, SIGNAL(textChanged()), this, SLOT(resize_url()));
    connect(ui->te_url->document(), SIGNAL(contentsChange(int, int, int)), this
            , SLOT(cleanup_color_url(int , int, int)));
}

Layer::~Layer()
{
    delete ui;
}

void Layer::set_url(QUrl &url)
{
    if (url.scheme() == "http")
        ui->lb_ssl->setPixmap(ui->pm_ssl_off);
    else
        ui->lb_ssl->setPixmap(ui->pm_ssl);

    QString host = url.host();
    host.replace("www.", "", Qt::CaseInsensitive);
    ui->te_url->setHtml("<font color=\"white\">"+host+"</font>"+"<font color=\"gray\">"+url.path()+url.fragment()+"</font>");
    ui->te_url->setAlignment(Qt::AlignCenter);
    ui->te_url->moveCursor(QTextCursor::End);
}

void Layer::set_visible(QWidget *w_browser)
{
    if (this->isHidden()) {
        this->setParent(NULL);
        this->setParent(w_browser);
        this->setVisible(true);
        ui->te_url->verticalScrollBar()->setValue(3);
        ui->te_url->setFocus();
    } else {
        this->setHidden(true);
        w_browser->setFocus();
    }
}

void Layer::cleanup_color_url(int p, int cr, int ca)
{
    Q_UNUSED(p);
    if (cr > 1 && ca == 1) {
        ui->te_url->selectAll();
        ui->te_url->setTextColor(QColor(255, 255, 255));
        ui->te_url->moveCursor(QTextCursor::End);
        ui->te_url->document()->setTextWidth(399);
    }
}

void Layer::resize_url()
{
    if ((ui->te_url->document()->size().width()) > 400)
        if (ui->te_url->document()->toPlainText().simplified().isEmpty())
            ui->te_url->setMinimumWidth(500);
        else
            ui->te_url->setMinimumWidth(ui->te_url->document()->idealWidth() + 100);
    else
        ui->te_url->setMinimumWidth(500);
}
