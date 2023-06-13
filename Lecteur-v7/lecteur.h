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
#include "database.h"
#include "diaporama.h"
#include "regleurdiaporama.h"
#include "modifierdiaporama.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lecteur; }
QT_END_NAMESPACE

class Lecteur : public QMainWindow
{
    Q_OBJECT

public:
    Lecteur(QWidget *parent = nullptr); // Constructeur
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    ~Lecteur(); //Destructeur
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    void chargerDiaporama(unsigned int pNumDiaporama);    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete
    void setPosImageCourante(unsigned int posImage); // Se positionner dans le diapo
    float getTimeAuto(); // temp du mode auto pour changer d'image
    void setTimeAuto(float temps); // changer le temp du mode auto entre les images
    void avancer(); // Fonction pour faire avancer le diapo et afficher
    void reculer(); // Fonction reculer et afficher

private:
    Diaporama *_diaporama;            // pointeurs vers les images du diaporama
    QTimer *timerModeAuto; // Timer pour le mode Auto
    bool _modeAuto; // Mode Auto activer ?
    float _timeAuto = 5; // Temp en sec du mode auto
    Ui::Lecteur *ui;
    Database mydb; // Base de donnes
private slots :
    void btnAvancer(); // Lorsque le boutton avancer est cliquer ou par le ficher > Avancer, desactive mode auto si actif
    void btnReculer(); // Idem pour reculer
    void modeLecture(); // Activer/Desactiver le mode Lecture
    void aProposDe(); // Affiche un message a propos de
    void modeAutoAvancer(); // Avancer tout les x seconde
    void demandeChangementVitesse(); // Ouvre la fenetre pour changer la duree du mode auto
    void changerVitesse(float temps); // Nouvelle valeur du temps auto
    void btnChargerDiaporama();// charger le diapo ouvre une fenetre pour que l'utilisateur saisie le diapo a selectionner
    void btnEnleverDiaporama(); // vider diapo
    void chargerDiapo(unsigned int num); // Charge les images du diaporama
    void demandeChangementModifierDiapo(); // Ouvre la fenetre pour modifier le diaporama courant
    void modifierDiaporama(QString intituleDiapo, QString intituleImage, QString cheminImage, unsigned int rangImage); // Modifie les éléments du diapo
};
#endif // LECTEUR_H
