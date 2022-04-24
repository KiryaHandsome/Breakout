#include "paddle.h"
#include <QDebug>

const int win_width = 800;
const int win_height = 600;

Paddle::Paddle(QWidget* parent) : QLabel(parent)
{
    QPixmap pixmap(":/ArcanoidPaddle.png");
    this->setPixmap(pixmap);
    this->setStyleSheet("background-color:black");
    dir_x = win_width / 2 - pixmap.width() / 2;
    this->setGeometry(dir_x, win_height - _height - 50, pixmap.width(), pixmap.height());
}

void Paddle::stop_move()
{
    move_to = Stop;
}


void Paddle::move_left()
{
    move_to = Left;
}

void Paddle::move_right()
{
    move_to = Right;
}

bool Paddle::isMoveLeft() const
{
    return move_to == Left;
}

bool Paddle::isStopped() const
{
    return move_to == Stop;
}

void Paddle::move()
{
    if(dir_x  + move_to * offset > 0 && dir_x + move_to * offset - 5 + _width < win_width) dir_x += move_to * offset;
    this->setGeometry(dir_x, win_height - _height - 50, _width, _height);
}
