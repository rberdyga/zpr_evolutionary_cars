#ifndef BOARD_H
#define BOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class Board : public QFrame
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);

public slots:
    void start();
    void pause();

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    enum {BoardWidth = 10, BoardHeight = 22};

    QBasicTimer timer;

    bool isStarted;
    bool isPaused;

    int timeoutTime();

    void clearBoard();
};

#endif // BOARD_H
