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
