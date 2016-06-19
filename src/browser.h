#ifndef BROWSER_H
#define BROWSER_H

#include "view.h"
#include "layer.h"
#include "ui.h"

#include <QEvent>
#include <QKeyEvent>

namespace Ui {
class Browser;
}

class Browser : public QWidget
{
    Q_OBJECT

public:
    Browser(QWidget *parent = 0);
    ~Browser();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    View *view;
    Layer *layer;
    Ui::Browser *ui;

    std::vector<View *> vectorViews;

private slots:
    void init_view();
    void init_layer();
    void show_layer();
};

#endif // BROWSER_H
