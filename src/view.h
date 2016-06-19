#ifndef VIEW_H
#define VIEW_H

#include "ui.h"

#include <QWebEngineView>

namespace Ui {
class View;
}

class View : public QWebEngineView
{
    Q_OBJECT

public:
    explicit View(QWebEngineView *parent = 0);
    ~View();

public slots:
    void load_url(QString url);

private:
    Ui::View *ui;
};

#endif // VIEW_H
