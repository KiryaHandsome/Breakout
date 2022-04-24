#ifndef BRICK_H
#define BRICK_H

#include <QLabel>


class Brick : public QLabel
{
private:
    int x, y;
public:
    Brick(int x = 100, int y = 40, QWidget* parent = nullptr);
    void set_x(int x);
    void set_y(int y);

    static const int width = 64, height = 32;
};

#endif // BRICK_H
