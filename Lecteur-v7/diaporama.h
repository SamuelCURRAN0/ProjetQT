#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include "image.h"
#include <QSqlQuery>

typedef vector<Image*> listeImage;
class Diaporama
{
public:
    Diaporama(); // Constructeur
    void Avancer(); // Avance de 1 dans le diaporama
    void Reculer(); // Recule de 1 dans le diaporama
    void setPosImageCourante(unsigned int posImage); // Aller a posImage dans le diaporama
    unsigned int nbImages();    // retourne la taille (nombre d'image) du diaporama
    unsigned int numImagesCourante();
    void echangerImage(unsigned int indiceImageUne, unsigned int indiceImageDeux); //Echange de place deux images du diaporama
    bool chargerDiaporama(unsigned int pNumDiaporama); // Charge le diaporama, renvoie faux si echec
    void viderDiaporama(); // vide le diaporama
    bool diaporamaCharger(); // Vrai -> Diapo pas vide, Faux -> Diapo vide
    Image* imageCourante(); // Retourne l'image courante
private:
    listeImage _imageDiapo;   // Structure de données contenant les infos sur les images
    unsigned int _numImageCourant;   // numéro du diaporama courant, commence a 1
};

#endif // DIAPORAMA_H
