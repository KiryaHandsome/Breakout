#include "breakout.h"
#include "ui_breakout.h"
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>

Breakout::Breakout(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Breakout), bricks(bricks_rows, std::vector<Brick*>(bricks_columns))
{
    this->setFixedSize(win_width, win_height);
    paddle = new Paddle(this);
    //Brick* brick = new Brick(10 ,10, this);
    for(size_t i = 0; i < bricks_rows; ++i){
        for(size_t j = 0; j < bricks_columns; ++j){
            bricks[i][j] = new Brick(10 + j * 64, 10 + i * 32, this);
        }
    }
    ball = new Ball(win_width / 2, win_height / 2, this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_ball()));

    paddleTimer = new QTimer(this);
    connect(paddleTimer, SIGNAL(timeout()), this, SLOT(move_paddle()));
}

Breakout::~Breakout()
{
    for(size_t i = 0; i < bricks_rows; ++i){
        for(size_t j = 0; j < bricks_columns; ++j){
            delete bricks[i][j];
        }
    }
    delete timer;
    delete ball;
    delete paddle;
    delete ui;
}

bool Breakout::isWin(){
    for(size_t i = 0; i < bricks_rows; ++i){
        for(size_t j = 0; j < bricks_columns; ++j){
            if(bricks[i][j]){
                return false;
            }
        }
    }
    return true;
}

void Breakout::ballTouchBricks()
{
    auto box = [&](){
        for(size_t i = 0; i < bricks_rows; ++i)
        {
            for(size_t j = 0; j < bricks_columns; ++j)\
            {
                if(bricks[i][j] && (*bricks[i][j]).geometry().intersects(ball->geometry()))
                {
                    int ball_x = ball->geometry().x();
                    int brick_x = bricks[i][j]->geometry().x();
                    if(ball_x + ball->width + 2 <= brick_x || ball_x >= brick_x + bricks[i][j]->width - 2)
                    {
                        ball->set_dx(-ball->get_dx());
                    }
                    else
                    {
                        ball->set_dy(-ball->get_dy());
                    }
                    intensive += 2;
                    timer->start(1000 / intensive);
                    delete bricks[i][j];
                    bricks[i][j] = nullptr;
                    if(isWin()){
                        timer->stop();
                        paddleTimer->stop();
                        QMessageBox::information(this, "Win", "You win!");
                    }
                    return;
                }
            }
        }
    };

    box();
}

void Breakout::keyPressEvent(QKeyEvent *event)
{
    if(!timer->isActive())
    {
        timer->start(1000 / 80);
        paddleTimer->start(1000 / 60);
    }

    if(event->key() == Qt::Key_Left){
        //move left
        if(paddle->geometry().x() > 0){
            paddle->move_left();
        }
    }
    if(event->key() == Qt::Key_Right){
        //move right, 128 - width of paddle
        if(paddle->geometry().x() < win_width - 128) {
            paddle->move_right();
        }
    }
}

void Breakout::move_ball()
{
    int new_x = ball->get_x() + ball->get_dx();
    int new_y = ball->get_y() + ball->get_dy();
    int ball_side = 24;
    if(new_x + ball_side >= win_width || new_x <= 0){
        ball->set_dx(-ball->get_dx());
    }
    if(new_y <= 0){
        ball->set_dy(-ball->get_dy());
    }

    if(ball->geometry().intersects(paddle->geometry())){
//        if(paddle->isMoveLeft() || ball->geometry().x() < paddle->x() + paddle->_width / 3){
//            ball->set_dx(-2);
//            ball->set_dy(-2);
//        }
//        else if(ball->geometry().x() > paddle->x() + paddle->_width / 3
//                && ball->geometry().x() + 24 < paddle->x() + paddle->_width * 2 / 3){
//            ball->set_dx(0);
//            ball->set_dy(-2);
//        }
//        else {
//            ball->set_dy(-ball->get_dy());
//        }
        ball->set_dy(-ball->get_dy());

    }

    if(new_y + ball_side >= win_height){
        timer->stop();
        paddleTimer->stop();
        QMessageBox::information(this, "Oops", "You lose :( ");
    }

    ballTouchBricks();

    ball->move();
}

void Breakout::move_paddle()
{
    paddle->move();
    //qDebug() << "move";
}

void Breakout::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    paddle->stop_move();
}

