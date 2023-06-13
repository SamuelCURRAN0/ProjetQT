#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <QLabel>
using namespace std;

class Image
{
public:
    Image(unsigned int codeImage, unsigned int pRang,
              string pCategorie="", string pTitre="", string pChemin = ""); // Constructeur image
    unsigned int getRang();     // getter du rang
    string getCategorie();      // getter de Categorie
    string getTitre();          // getter du Titre
    string getChemin();         // getter du chemin
    unsigned int getCodeImage(); // getter du code
private:
    unsigned int _codeImage; // code de l'image
    unsigned int _rang;         /* rang de l'image au sein du diaporama
                                   auquel l'image est associée */
    string _titre;              // intitulé de l'image
    string _categorie;          // catégorie de l'image (personne, animal, objet)
    string _chemin;             // chemin complet vers le dossier où se trouve l'image
};

#endif // IMAGE_H
