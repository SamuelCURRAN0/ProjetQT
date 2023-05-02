#include "lecteurvue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue w;
    qDebug("test");

    w.show();
    return a.exec();
}
