#include "modifierdiaporama.h"
#include "ui_modifierdiaporama.h"

ModifierDiaporama::ModifierDiaporama(QWidget *parent, QString intituleDiapo, QString intituleImage, QString cheminImage, unsigned int rangImage) :
    QDialog(parent),
    ui(new Ui::ModifierDiaporama)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(confirmerModification()));
    ui->ChampIntituleDiapo->setText(intituleDiapo);
    ui->ChampIntituleImage->setText(intituleImage);
    ui->ChampChemin->setText(cheminImage);
    ui->ChampRang->setText(QString::number(rangImage));
}


void ModifierDiaporama::confirmerModification()
{
    bool ok;
    unsigned int numRang = ui->ChampRang->text().toUInt(&ok);
    if(ok)
    {
        emit modifierDiaporama(ui->ChampIntituleDiapo->text(), ui->ChampIntituleImage->text(), ui->ChampChemin->text(), numRang);
        return;
    }
    QMessageBox messageBox;
    messageBox.critical(0,"Erreur","Saisie incorecte !");
    messageBox.setFixedSize(500,200);
}

ModifierDiaporama::~ModifierDiaporama()
{
    delete ui;
}
