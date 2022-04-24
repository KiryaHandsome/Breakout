#include "ball.h"

#include <QDebug>

Ball::Ball(int x, int y, QWidget* parent) : QLabel(parent), x(x), y(y)
{
    QPixmap pixmap(":/ArcanoidBall.png");
    this->setPixmap(pixmap);
    this->setGeometry(x, y, 24, 24);
}

void Ball::move()
{
    x += dx;
    y += dy;
    this->setGeometry(x, y, width, height);
}

void Ball::set_dx(int dx)
{
    this->dx = dx;
}

void Ball::set_dy(int dy)
{
    this->dy = dy;
}

int Ball::get_dx() const
{
    return dx;
}

int Ball::get_dy() const
{
    return dy;
}

int Ball::get_x() const
{
    return x;
}
int Ball::get_y() const
{
    return y;
}
