#ifndef PADDLE_H
#define PADDLE_H

#include <QLabel>
#include <queue>

class Paddle : public QLabel
{
private:
    int dir_x = 0;
    char move_to = 0;
    enum { Left = -1, Stop, Right};
public:
    Paddle(QWidget* parent = nullptr);

    void stop_move();
    void move_left();
    void move_right();
    bool isMoveLeft() const;
    bool isStopped() const;

    void move();

    static const int _width = 128, _height = 24;
    static const int offset = 12;
};

#endif // PADDLE_H
