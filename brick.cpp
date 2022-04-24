#include "brick.h"
#include <QDebug>

Brick::Brick(int x, int y, QWidget* parent) : QLabel(parent), x(x), y(y)
{
    QPixmap pixmap(":/ArcanoidBrick.png");
    this->setPixmap(pixmap);
    this->setGeometry(x, y, width, height);
    //qDebug() << pixmap.width() << pixmap.height();
}

void Brick::set_x(int x)
{
    this->x = x;
    this->setGeometry(this->x, this->y, width, height);
}

void Brick::set_y(int y)
{
    this->y = y;
    this->setGeometry(this->x, this->y, width, height);
}
