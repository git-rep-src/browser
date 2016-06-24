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
    bool eventFilter(QObject *o, QEvent *e);

private:
    View *view;
    Layer *layer;

    QUrl url;
    std::vector<View *> views;

    int row;
    int col;
    int current;

    Ui::Browser *ui;

private slots:
    void create_view();
    void create_layer();
    void handler_view(int offset = 0, bool open = false);
    void handler_layer();
};

#endif // BROWSER_H
