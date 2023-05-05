#include "lecteurvue.h"
#include "ui_lecteurvue.h"

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Statut du diapo");

    connect(ui->actionAvancer, SIGNAL(triggered()), this, SLOT(avancer()));
    connect(ui->actionArri_re, SIGNAL(triggered()), this, SLOT(reculer()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));


    connect(ui->bAvant, SIGNAL(clicked()), this, SLOT(avancer()));
    connect(ui->bArriere, SIGNAL(clicked()), this, SLOT(reculer()));
    connect(ui->bModeLecture, SIGNAL(clicked()), this, SLOT(modeLecture()));
}

lecteurVue::~lecteurVue()
{
    delete ui;
}

void lecteurVue::avancer()
{
    qDebug("avancer");
}

void lecteurVue::reculer()
{
    qDebug("arriere");
}

void lecteurVue::modeLecture()
{
    qDebug("Change de mode");
}

