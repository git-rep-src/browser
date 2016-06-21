#ifndef MINIPAGEBUTTON_H
#define MINIPAGEBUTTON_H

#include <QWidget>
#include <QMouseEvent>

class MiniPageButton : public QWidget
{
    Q_OBJECT
public:
    explicit MiniPageButton(QWidget *parent = 0);
    ~MiniPageButton();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // MINIPAGEBUTTON_H
