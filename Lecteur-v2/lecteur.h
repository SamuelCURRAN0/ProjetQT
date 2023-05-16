#ifndef LECTEUR_H
#define LECTEUR_H

#include <QMainWindow>
#include <QtCore/QDebug>
#include <QtGui/QImage>
#include "image.h"
#include <vector>

typedef vector<Image*> Diaporama;   // Structure de données contenant les infos sur les images

QT_BEGIN_NAMESPACE
namespace Ui { class Lecteur; }
QT_END_NAMESPACE

class Lecteur : public QMainWindow
{
    Q_OBJECT

public:
    Lecteur(QWidget *parent = nullptr);
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    void echangerImage(unsigned int indiceImageUne, unsigned int indiceImageDeux);
    ~Lecteur();
    unsigned int nbImages();    // affiche la taille de _diaporama
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    unsigned int numDiaporamaCourant();
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete

private:
    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
    Ui::Lecteur *ui;

private slots :
    void reculer(); // décrémente _posImageCourante, modulo nbImages()
    void avancer();// incrémente _posImageCourante, modulo nbImages()
    void modeLecture();
};
#endif // LECTEUR_H
