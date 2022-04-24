#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
#include <vector>
#include "paddle.h"
#include "brick.h"
#include "ball.h"

const static int win_width = 800, win_height = 600;
//const static int paddle_width = 128, paddle_height = 28;


QT_BEGIN_NAMESPACE
namespace Ui { class Breakout; }
QT_END_NAMESPACE

class Breakout : public QWidget
{
    Q_OBJECT

    size_t bricks_rows = 6;
    size_t bricks_columns = 12;
    //speed parameter of ball
    int intensive = 60;

public:
    Breakout(QWidget *parent = nullptr);
    ~Breakout();

    void ballTouchBricks();
    bool isWin();


private slots:
    void keyPressEvent(QKeyEvent* event);
    void move_ball();
    void move_paddle();
    void keyReleaseEvent(QKeyEvent *event);

private:
    Paddle* paddle;
    Ball* ball;
    Ui::Breakout *ui;
    std::vector<std::vector<Brick*>> bricks;
    QTimer* timer;
    QTimer* paddleTimer;

};
#endif // BREAKOUT_H
