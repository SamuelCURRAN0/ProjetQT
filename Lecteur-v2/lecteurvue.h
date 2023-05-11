#ifndef LECTEURVUEV1_H
#define LECTEURVUEV1_H

#include <QMainWindow>
#include <QtCore/QDebug>
#include <QtGui/QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class lecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();
private slots :
    void reculer();
    void avancer();
    void modeLecture();
private:
    Ui::lecteurVue *ui;
};
#endif // LECTEURVUEV1_H
