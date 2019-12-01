#include <QtWidgets>

#include "window.h"
#include "board.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    //symulacja powinna byc w klasie Board
    //potrzeba klasy, ktora obsluzy symulacje.
    //
    //Board srednio zdaje egzamin.
    //
    //Calosc jest juz umieszczona w glownym oknie
    board = new Board;

    createWidgets();
    connectSignals();
    settingLayout();
}

void Window::createWidgets()
{
    populationSize = new QLCDNumber(5);
    populationSize->setSegmentStyle(QLCDNumber::Filled);
    mutationRate = new QLCDNumber(5);
    mutationRate->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);
}

void Window::settingLayout()
{
    QHBoxLayout *simulationLayout = new QHBoxLayout;
    simulationLayout->addWidget(board); //dodawanie glownej symulacji

    setButtonsSize(); //zakomentowac dla responsywnosci

    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(startButton,Qt::AlignHCenter);
    buttonsLayout->addWidget(pauseButton,Qt::AlignHCenter);
    buttonsLayout->addWidget(quitButton,Qt::AlignHCenter);

    QVBoxLayout *simParamLayout = new QVBoxLayout;
    simParamLayout->addWidget(createLabel(tr("Population Size")));
    simParamLayout->addWidget(populationSize);
    simParamLayout->addWidget(createLabel(tr("Mutation Rate")));
    simParamLayout->addWidget(mutationRate);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(simulationLayout,0,0,5,4);
    mainLayout->addLayout(buttonsLayout,0,4);
    mainLayout->addLayout(simParamLayout,1,4,3,1);

    this->setLayout(mainLayout);
    setWindowTitle(tr("Evolving Cars"));
    resize(1280, 720);
}

void Window::setButtonsSize()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    QSize btnSize = QSize(width/10, height/10);
    startButton->setFixedSize(btnSize);
    pauseButton->setFixedSize(btnSize);
    quitButton->setFixedSize(btnSize);
}

void Window::connectSignals()
{
    /*connect(startButton, &QPushButton::clicked, board, &Board::start);
    //connect(quitButton, &QPushButton::clicked, qApp, &Board::start);
    connect(pauseButton, &QPushButton::clicked, board, &Board::pause);*/

    //#if __cplusplus >= 201402L
        //connect(board, &Board::)
}

QLabel *Window::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}
