#include "lecteur.h"

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
}

void Lecteur::avancer()
{
    _posImageCourante++;
    if(_posImageCourante > nbImages())
    {
        _posImageCourante = 1;
    }
}

void Lecteur::reculer()
{
    _posImageCourante--;
    if( _posImageCourante < 1)
    {
        _posImageCourante = (*this).nbImages();
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

void Lecteur::echangerImage(Image* imageUne, Image* imageDeux)
{
    Image copieImage = imageUne;
    imageUne = imageDeux;
    imageDeux = copieImage;
}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "C:\\cartesDisney\\carteDisney2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Cendrillon", "C:\\cartesDisney\\carteDisney4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Grincheux", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);
    cout << "Le diaporama a ete charger avec "  << nbImages() << "Images "<< endl;
     // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    for(unsigned int i = 0; i < nbImages(); i++)
    {
        for(unsigned int idice2 = i+1; idice2 < nbImages(); idice2++)
        {
            if(_diaporama[i]->getRang()> _diaporama[idice2]->getRang())
            {
                echangerImage(_diaporama[i], _diaporama[idice2]);
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
    if(_numDiaporamaCourant == 0)
    {
        cout << "Aucun diaporama charger" << endl;
    }
    else
    {
        if(_posImageCourante <= nbImages() && _posImageCourante != 0)
        {
            cout << "Affichage";
            (*this).imageCourante()->afficher();
        }
        else
        {
            cout << "Pas d'image" << endl;
        }
    }
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
