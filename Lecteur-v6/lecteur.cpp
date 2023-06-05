#include "lecteur.h"
#include "ui_lecteur.h"

Lecteur::Lecteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lecteur)
{
    _diaporama = new Diaporama();
    ui->setupUi(this);
    _modeAuto = false;
    ui->statusbar->showMessage("Mode Manuel");
    connect(ui->actionAvancer, SIGNAL(triggered()), this, SLOT(btnAvancer()));
    connect(ui->actionArriere, SIGNAL(triggered()), this, SLOT(btnReculer()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));
    connect(ui->actionVitesse, SIGNAL(triggered()), this, SLOT(demandeChangementVitesse()));
    connect(ui->actionChargerDiaporama, SIGNAL(triggered()), this, SLOT(btnChargerDiaporama()));
    connect(ui->actionEnleverDiaporama, SIGNAL(triggered()), this, SLOT(btnEnleverDiaporama()));

    connect(ui->bAvant, SIGNAL(clicked()), this, SLOT(btnAvancer()));
    connect(ui->bArriere, SIGNAL(clicked()), this, SLOT(btnReculer()));
    connect(ui->bModeLecture, SIGNAL(clicked()), this, SLOT(modeLecture()));
    if(!mydb.openDataBase())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Erreur lors de l'ouverture BD");
        messageBox.setFixedSize(500,200);
    }
    viderDiaporama();
}

void Lecteur::chargerDiaporama(unsigned int pNumDiaporama)
{
    _diaporama->chargerDiaporama(pNumDiaporama);
    ui->bAvant->setEnabled(true);
    ui->bArriere->setEnabled(true);
    ui->bModeLecture->setEnabled(true);
    ui->actionAvancer->setEnabled(true);
    ui->actionArriere->setEnabled(true);
    afficher();

}
void Lecteur::viderDiaporama()
{
    _diaporama->viderDiaporama();
    ui->bAvant->setEnabled(false);
    ui->bArriere->setEnabled(false);
    ui->bModeLecture->setEnabled(false);
    ui->actionAvancer->setEnabled(false);
    ui->actionArriere->setEnabled(false);
    ui->TexteNumeroImage->setText("numero image / nbr image");
    ui->TexteCategorie->setText("*catégorie de l'image*");
    ui->TexteTitre->setText("*titre de l'image*");
    ui->Image->setText("Image");

    if(_modeAuto)
    {
        modeLecture(); //Désactiver le mode Auto si il est Actif
    }

}

void Lecteur::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setText("Créee par :\r\n- Curran Samuel\r\n- Beltzer Gabriel\r\n- Eyherabide Kepa.\r\nCréee le : 05/06/2023.\r\nVersion : v6");
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setGeometry(700,500,150,100);
    msgBox->setSizeGripEnabled(false);
    msgBox->exec();
}


void Lecteur::afficher()
{
    /* affiche les information sur le lecteur :
     * 1) vide (si num. de diaporama = 0) OU BIEN  numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante OU BIEN 'diaporama vide'
     *     si ce diaporama n'a aucun image */
    qDebug("afficher");
    ui->TexteNumeroImage->setText(QString::number(_diaporama->numImagesCourante()) + "/" + QString::number(_diaporama->nbImages()));
    if(_diaporama->diaporamaCharger())
    {
        QString chemin = QString::fromStdString(_diaporama->imageCourante()->getChemin());
        QString categorie = QString::fromStdString(_diaporama->imageCourante()->getCategorie());
        QString titre =  QString::fromStdString(_diaporama->imageCourante()->getTitre());
        ui->TexteCategorie->setText(categorie);
        ui->TexteTitre->setText(titre);
        ui->Image->setPixmap(QPixmap(chemin));
    }
    else
    {
        qDebug("Aucun diaporama charger");
    }
}
void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (_diaporama->diaporamaCharger())
    {
        viderDiaporama();
    }
    chargerDiaporama(pNumDiaporama); // charge le diaporama courant
}
Lecteur::~Lecteur()
{
    delete ui;
}
void Lecteur::setPosImageCourante(unsigned int posImage)
{
    _diaporama->setPosImageCourante(posImage);
    afficher();
}
void Lecteur::avancer()
{
    _diaporama->Avancer();
    afficher();
}
void Lecteur::reculer()
{
    _diaporama->Reculer();
    afficher();
}

void Lecteur::btnAvancer()
{
    if(_modeAuto)
    {
        modeLecture(); // Activer par les boutton pas par le mode Auto, si en mode Auto passer en mode manuel
    }
   avancer();
}

void Lecteur::btnReculer()
{
    if(_modeAuto)
    {
        modeLecture(); // Activer par les boutton pas par le mode Auto, si en mode Auto passer en mode manuel
    }
    reculer();
}

void Lecteur::modeAutoAvancer()
{
    avancer();
}
void Lecteur::modeLecture()
{
    qDebug("Change de mode");
    _modeAuto = _modeAuto?false:true;
    ui->statusbar->showMessage(_modeAuto?"Passage en mode Automatique":"Passage en mode Manuel");
    ui->bModeLecture->setText(_modeAuto?"Arrêter Diaporama":"Démarrer Diaporama");
    if(_modeAuto)
    {
        setPosImageCourante(1);
        timerModeAuto = new QTimer(this);
        connect(timerModeAuto, SIGNAL(timeout()), this, SLOT(modeAutoAvancer()));
        timerModeAuto->start(_timeAuto*1000);

    }
    else
    {
        disconnect(timerModeAuto, SIGNAL(timeout()), this, SLOT(modeAutoAvancer()));
    }

}
void Lecteur::demandeChangementVitesse()
{
    RegleurVitesse* rv = new RegleurVitesse(this, getTimeAuto());
    connect(rv, SIGNAL(changerVitesse(float)), this, SLOT(changerVitesse(float)));
    rv->exec();
}
float Lecteur::getTimeAuto()
{
    return _timeAuto;
}
void Lecteur::setTimeAuto(float temps)
{
    _timeAuto = temps;
}
void Lecteur::changerVitesse(float temps)
{
    setTimeAuto(temps);
}
void Lecteur::btnChargerDiaporama()
{
    changerDiaporama(1);
}
void Lecteur::btnEnleverDiaporama()
{
    viderDiaporama();
}
