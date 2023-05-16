#include "lecteur.h"
#include "ui_lecteur.h"

Lecteur::Lecteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lecteur)
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
    ui->setupUi(this);
    ui->statusbar->showMessage("Statut du diapo");

    connect(ui->actionAvancer, SIGNAL(triggered()), this, SLOT(avancer()));
    connect(ui->actionArri_re, SIGNAL(triggered()), this, SLOT(reculer()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));


    connect(ui->bAvant, SIGNAL(clicked()), this, SLOT(avancer()));
    connect(ui->bArriere, SIGNAL(clicked()), this, SLOT(reculer()));
    connect(ui->bModeLecture, SIGNAL(clicked()), this, SLOT(modeLecture()));
}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "F:\\traveaux-pratiques\\cartesDisney\\carteDisney2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Cendrillon", "F:\\traveaux-pratiques\\cartesDisney\\carteDisney4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "F:\\traveaux-pratiques\\cartesDisney\\carteDisney3.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Grincheux", "F:\\traveaux-pratiques\\cartesDisney\\carteDisney1.gif");
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

    _posImageCourante = 0;

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

void Lecteur::avancer()
{
    qDebug("avancer");
    _posImageCourante++;
    if(_posImageCourante > nbImages())
    {
        _posImageCourante = 1;
    }
    afficher();
}

void Lecteur::reculer()
{
    qDebug("arriere");
    _posImageCourante--;
    if( _posImageCourante < 1)
    {
        _posImageCourante = (*this).nbImages();
    }
    afficher();
}

void Lecteur::modeLecture()
{
    qDebug("Change de mode");
}
