#ifndef BALL_H
#define BALL_H

#include <QLabel>

class Ball : public QLabel
{
private:
    int x = 0, y = 0;
    int dx = -2, dy = 2;


public:
    Ball(int x, int y, QWidget* parent = nullptr);
    void move();
    int get_x() const;
    int get_y() const;
    int get_dx() const;
    int get_dy() const;
    void set_dx(int dx);
    void set_dy(int dy);


    const static int width = 24, height = 24;
};

#endif // BALL_H
