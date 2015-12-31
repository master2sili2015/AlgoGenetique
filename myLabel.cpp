#include "myLabel.h"

MyLabel::MyLabel(const QString& text, QWidget* parent) : QLabel(parent)
{
    setText(text);
}
 
MyLabel::~MyLabel()
{
}
 
void MyLabel::mousePressEvent(QMouseEvent * event)
{
    emit clicked();
}