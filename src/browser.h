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
    View *pView;
    Layer *pLayer;
    Ui::Browser *ui;

    int row = 0;
    int col = 0;
    int currentView = 0;
    std::vector<View *> vectorView;

private slots:
    void view();
    void layer();
    void layer_handle();
    void miniature_handler(int min = 0, bool open = false);
};

#endif // BROWSER_H
