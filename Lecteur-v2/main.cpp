#include "lecteur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lecteur w;
    w.show();
    w.changerDiaporama(1);
    return a.exec();
}
