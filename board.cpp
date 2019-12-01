/* wersja z QGraphicsScene
 *
 * #include "board.h"

Board::Board(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    QGraphicsView view(scene);
    view.show();


    scene->addText("Hello, world!");
    scene->setBackgroundBrush(Qt::blue);
} */


#include <QtWidgets>

#include "board.h"

/**** public ****/

Board::Board(QWidget *parent) : QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);

    isStarted = false;
    isPaused = false;

    clearBoard();
}

/**** public slots ****/

void Board::start()
{
    if(isPaused) return;

    isStarted = true;

    //...

    timer.start(timeoutTime(), this);
}

void Board::pause()
{
    if(!isStarted) return;

    isPaused = !isPaused;

    if (isPaused) timer.stop();
    else timer.start(timeoutTime(), this);

    update();
}

/**** protected ****/

void Board::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect = contentsRect();

    if(isPaused)
    {
        painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
        return;
    }
}
void Board::keyPressEvent(QKeyEvent *event)
{
    /*if(!isStarted || isPaused == Noshape)
    {
        QFrame::keyPressEvent(event);
        return;
    }*/

    /*switch (event->key())
    {
    case Qt::Key_Left:
    }*/



}

void Board::timerEvent(QTimerEvent *event)
{

}

/**** private ****/

int Board::timeoutTime()
{
    return 1000;
}

void Board::clearBoard()
{

}
