#include "layer.h"

Layer::Layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Layer)
{
    ui->setupUi(this);

    connect(ui->lineedit_url, SIGNAL(textChanged(QString)), this, SLOT(resizeLineEditUrl()));
}

Layer::~Layer()
{
    delete ui;
}

void Layer::set_url(QUrl &url)
{
    if (url.scheme() == "http")
        ui->label_ssl->setPixmap(ui->pixmap_ssl_off);
    else
        ui->label_ssl->setPixmap(ui->pixmap_ssl);

    ui->lineedit_url->setText(url.toString().replace(0, url.scheme().size()+3, ""));

}

void Layer::set_visible(QWidget *widget_browser)
{
    if (this->isHidden()) {
        this->setParent(NULL);
        this->setParent(widget_browser);
        this->setVisible(true);
        ui->lineedit_url->setFocus();
    } else {
        this->setHidden(true);
    }
}

void Layer::resizeLineEditUrl()
{
    QFont f("", 0);
    QFontMetrics fm(f);
    int pixelsWide = fm.width(ui->lineedit_url->text());
    if (pixelsWide > 160)
        ui->lineedit_url->setMinimumWidth(pixelsWide * 2.9);
    else
        ui->lineedit_url->setMinimumWidth(500); // TODO: %
    this->adjustSize();
}
