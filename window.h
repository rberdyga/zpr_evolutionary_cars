#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

//#include <QFrame>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class Board; //rozwazyc #include <board.h>


class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    QLabel *createLabel(const QString &text);

    Board *board;

    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

    QLCDNumber *populationSize;
    QLCDNumber *mutationRate;

    void createWidgets();
    void connectSignals();
    void settingLayout();
    void setButtonsSize();
};

#endif // WINDOW_H
