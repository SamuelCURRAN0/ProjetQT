#include "image.h"

Image::Image(unsigned int pRang, string pCategorie, string pTitre, string pChemin)
{
    _rang = pRang;
    _categorie = pCategorie;
    _titre = pTitre;
    _chemin = pChemin;
}
Image::Image(Image& ImageOriginale)
{
    _rang = ImageOriginale._rang;
    _categorie = ImageOriginale._categorie;
    _titre = ImageOriginale._titre;
    _chemin = ImageOriginale._chemin;
}
unsigned int Image::getRang()
{
    return _rang;
}

string Image::getCategorie()
{
    return _categorie;
}

string Image::getTitre()
{
    return _titre;
}

string Image::getChemin()
{
    return _chemin;
}

void Image::afficher(QLabel* labelSupport, QLabel* titreLabel, QLabel* categorieLabel)
{
    cout << "image( rang:" << getRang() << ", titre:" << getTitre() << ", categorie:"
         << getCategorie() << ", chemin:"<< getChemin() << ")" << endl;

    //on donne l'image au label
    labelSupport->setPixmap(QPixmap(QString::fromStdString(getChemin())));
    titreLabel->setText(QString::fromStdString(getTitre()));
    categorieLabel->setText(QString::fromStdString(getCategorie()));
    labelSupport->show();
}
