#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window* w = new Window();
    w->show();

    return a.exec();
}
