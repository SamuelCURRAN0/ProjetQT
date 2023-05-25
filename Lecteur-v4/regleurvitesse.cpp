#include "regleurvitesse.h"
#include "ui_regleurvitesse.h"

RegleurVitesse::RegleurVitesse(QWidget *parent, float temps) :
    QDialog(parent),
    ui(new Ui::RegleurVitesse)
{
    ui->setupUi(this);
    ui->EntreeSeconde->setText(QString::number(temps));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(confirmerVitesse()));
}
void RegleurVitesse::confirmerVitesse()
{
    bool* ok = new bool();
    float vitesse = ui->EntreeSeconde->text().toFloat(ok);
    if(ok)
    {
        if(vitesse > 0)
        {
            emit changerVitesse(vitesse);
        }
    }
}
RegleurVitesse::~RegleurVitesse()
{
    delete ui;
}
