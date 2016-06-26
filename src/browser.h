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
    int current_view;

    Ui::Browser *ui;

private slots:
    void create_view();
    void handler_view(int view_to_open = -1);
};

#endif // BROWSER_H
