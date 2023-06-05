#include "regleurdiaporama.h"
#include "ui_regleurdiaporama.h"

RegleurDiaporama::RegleurDiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegleurDiaporama)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(confirmerDiapo()));
}

RegleurDiaporama::~RegleurDiaporama()
{
    delete ui;
}

void RegleurDiaporama::confirmerDiapo()
{
    bool* ok = new bool();
    unsigned int numDiapo = ui->saisieNumDiapo->text().toUInt(ok);
    if(ok)
    {
        if(numDiapo >= 0)
        {
            emit changerDiapo(numDiapo);
            return;
        }
    }
    QMessageBox messageBox;
    messageBox.critical(0,"Erreur","Saisie incorecte !");
    messageBox.setFixedSize(500,200);
}
