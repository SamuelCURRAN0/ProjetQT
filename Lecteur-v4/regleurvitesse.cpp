#include "regleurvitesse.h"
#include "ui_regleurvitesse.h"

RegleurVitesse::RegleurVitesse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegleurVitesse)
{
    ui->setupUi(this);
}

RegleurVitesse::~RegleurVitesse()
{
    delete ui;
}
