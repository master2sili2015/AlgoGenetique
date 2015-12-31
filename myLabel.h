#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
    explicit MyLabel(const QString& text = "", QWidget* parent = 0);
    ~MyLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent * event);
};
#endif