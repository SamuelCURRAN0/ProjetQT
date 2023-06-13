#include "image.h"

Image::Image(unsigned int codeImage,unsigned int pRang, string pCategorie, string pTitre, string pChemin)
{
    _codeImage = codeImage;
    _rang = pRang;
    _categorie = pCategorie;
    _titre = pTitre;
    _chemin = pChemin;
}
unsigned int Image::getCodeImage()
{
    return _codeImage;
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
