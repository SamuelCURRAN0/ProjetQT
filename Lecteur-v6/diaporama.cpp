#include "diaporama.h"

Diaporama::Diaporama()
{

}
void Diaporama::chargerDiaporama(unsigned int pNumDiaporama)
{
    QSqlQuery query;
    QString commande = "SELECT DiaposDansDiaporama.rang, Familles.nomFamille, Diapos.titrePhoto,Diapos.uriPhoto "
            "FROM DiaposDansDiaporama "
            "JOIN Diapos ON Diapos.idphoto = DiaposDansDiaporama.idDiapo "
            "JOIN Familles on Familles.idFamille = Diapos.idFam "
            "WHERE DiaposDansDiaporama.idDiaporama = 1;";
    query.prepare(commande);
    query.bindValue(":numDiapo", pNumDiaporama);
    query.exec();
    Image* imageACharger;
    for(int i = 0; query.next(); i++)
    {
         imageACharger = new Image(query.value(0).toUInt(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(), "F:\\traveaux-pratiques\\" + query.value(3).toString().toStdString());
         _imageDiapo.push_back(imageACharger);
    }

    // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    for(unsigned int indiceImageUne = 0; indiceImageUne < nbImages(); indiceImageUne++)
    {
        for(unsigned int indiceImageDeux = indiceImageUne+1; indiceImageDeux < nbImages(); indiceImageDeux++)
        {
            if(_imageDiapo[indiceImageUne]->getRang()> _imageDiapo[indiceImageDeux]->getRang())
            {
                echangerImage(indiceImageUne, indiceImageDeux);
            }
        }
    }
    setPosImageCourante(1);
    cout << "Diaporama num. " << pNumDiaporama << " selectionne. " << endl;
    cout << nbImages() << " images chargees dans le diaporama" << endl;
}

void Diaporama::echangerImage(unsigned int indiceImageUne, unsigned int indiceImageDeux)
{
    Image copieImage = *_imageDiapo[indiceImageUne];
    _imageDiapo[indiceImageUne] = _imageDiapo[indiceImageDeux];
    _imageDiapo[indiceImageDeux] = new Image(copieImage);
}
void Diaporama::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _imageDiapo.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
        _numImageCourant = 0;
    }
}

void Diaporama::setPosImageCourante(unsigned int posImage)
{
    _numImageCourant = posImage;
}
void Diaporama::Avancer()
{
    _numImageCourant++;
    if(_numImageCourant > nbImages())
    {
        _numImageCourant = 1;
    }
}
void Diaporama::Reculer()
{
    _numImageCourant--;
    if( _numImageCourant< 1)
    {
        _numImageCourant = (*this).nbImages();
    }
}
unsigned int Diaporama::nbImages()
{
    return _imageDiapo.size();
}
unsigned int Diaporama::numImagesCourante()
{
    return _numImageCourant;
}

Image* Diaporama::imageCourante()
{
    return _imageDiapo[_numImageCourant - 1];
}

bool Diaporama::diaporamaCharger()
{
    return nbImages() > 0;
}
