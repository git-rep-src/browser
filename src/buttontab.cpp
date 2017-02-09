#include "buttontab.h"

ButtonTab::ButtonTab(QWidget *parent) :
    QWidget(parent)
{
}

ButtonTab::~ButtonTab()
{
}

void ButtonTab::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();
}
