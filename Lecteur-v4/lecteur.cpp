#include "lecteur.h"
#include "ui_lecteur.h"

Lecteur::Lecteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lecteur)
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
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

}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "F:\\traveaux-pratiques\\cartesDisney\\Disney_2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Cendrillon", "F:\\traveaux-pratiques\\cartesDisney\\Disney_4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "F:\\traveaux-pratiques\\cartesDisney\\Disney_3.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Grincheux", "F:\\traveaux-pratiques\\cartesDisney\\Disney_1.gif");
    _diaporama.push_back(imageACharger);
    cout << "Le diaporama a ete charger avec "  << nbImages() << "Images "<< endl;
     // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    for(unsigned int indiceImageUne = 0; indiceImageUne < nbImages(); indiceImageUne++)
    {
        for(unsigned int indiceImageDeux = indiceImageUne+1; indiceImageDeux < nbImages(); indiceImageDeux++)
        {
            if(_diaporama[indiceImageUne]->getRang()> _diaporama[indiceImageDeux]->getRang())
            {
                echangerImage(indiceImageUne, indiceImageDeux);
            }
        }
    }
    setPosImageCourante(1);
    ui->bAvant->setEnabled(true);
    ui->bArriere->setEnabled(true);
    ui->bModeLecture->setEnabled(true);
    ui->actionAvancer->setEnabled(true);
    ui->actionArriere->setEnabled(true);
    cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
    cout << nbImages() << " images chargees dans le diaporama" << endl;
}
void Lecteur::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;
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
    msgBox->setText("Créee par :\r\n- Curran Samuel\r\n- Beltzer Gabriel\r\n- Eyherabide Kepa.\r\nCréee le : 03/05/2023.\r\nVersion : v4");
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
    ui->TexteNumeroImage->setText(QString::number(_posImageCourante) + "/" + QString::number(nbImages()));
    if(_numDiaporamaCourant == 0)
    {
        cout << "Aucun diaporama charger" << endl;
    }
    else
    {
        if(_posImageCourante <= nbImages() && _posImageCourante != 0)
        {
            cout << "Affichage";
            (*this).imageCourante()->afficher(ui->Image, ui->TexteTitre, ui->TexteCategorie);
        }
        else
        {
            cout << "Pas d'image" << endl;
        }
    }
}
void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }

}
void Lecteur::echangerImage(unsigned int indiceImageUne, unsigned int indiceImageDeux)
{
    Image copieImage = *_diaporama[indiceImageUne];
    _diaporama[indiceImageUne] = _diaporama[indiceImageDeux];
    _diaporama[indiceImageDeux] = new Image(copieImage);
}
unsigned int Lecteur::nbImages()
{
    return _diaporama.size();
}

Image *Lecteur::imageCourante()
{
    return _diaporama[_posImageCourante - 1];
}

unsigned int Lecteur::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}
Lecteur::~Lecteur()
{
    delete ui;
}
void Lecteur::setPosImageCourante(unsigned int posImage)
{
    _posImageCourante = posImage;
    afficher();
}
void Lecteur::btnAvancer()
{
    if(_modeAuto)
    {
        modeLecture();
    }
    avancer();
}

void Lecteur::btnReculer()
{
    if(_modeAuto)
    {
        modeLecture();
    }
    reculer();
}

void Lecteur::avancer()
{
    _posImageCourante++;
    if(_posImageCourante > nbImages())
    {
        _posImageCourante = 1;
    }
    afficher();
}

void Lecteur::reculer()
{
    _posImageCourante--;
    if( _posImageCourante < 1)
    {
        _posImageCourante = (*this).nbImages();
    }
    afficher();
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
bool Lecteur::diaporamaCharger()
{
    return nbImages()!=0;
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
