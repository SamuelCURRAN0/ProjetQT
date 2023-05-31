#ifndef LECTEUR_H
#define LECTEUR_H

#include <QMainWindow>
#include <QtCore/QDebug>
#include <QtGui/QImage>
#include "image.h"
#include <vector>
#include <QTimer>
#include <QMessageBox>
#include "regleurvitesse.h"

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
    void setPosImageCourante(unsigned int posImage);
    void reculer(); // décrémente _posImageCourante, modulo nbImages()
    void avancer();// incrémente _posImageCourante, modulo nbImages()
    float getTimeAuto();
    void setTimeAuto(float temps);
    bool diaporamaCharger();//Retourne vrai si diaporama charger, retourne faux sinon

private:
    unsigned int _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                       Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
    QTimer *timerModeAuto; // Timer pour le mode Auto
    bool _modeAuto; // Mode Auto activer ?
    float _timeAuto = 5; // Temp en sec du mode auto
    Ui::Lecteur *ui;

private slots :
    void btnAvancer(); // Lorsque le boutton avancer est cliquer ou par le ficher > Avancer
    void btnReculer(); // Idem pour reculer
    void modeLecture(); // Activer/Desactiver le mode Lecture
    void aProposDe(); // Affiche un message a propos de
    void modeAutoAvancer();
    void demandeChangementVitesse();
    void changerVitesse(float temps);
    void btnChargerDiaporama();
    void btnEnleverDiaporama();

};
#endif // LECTEUR_H
