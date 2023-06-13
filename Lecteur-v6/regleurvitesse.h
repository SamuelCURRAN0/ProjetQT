#ifndef REGLEURVITESSE_H
#define REGLEURVITESSE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class RegleurVitesse;
}

class RegleurVitesse : public QDialog
{
    Q_OBJECT

public:
    explicit RegleurVitesse(QWidget *parent, float temps);// Constructeur
    ~RegleurVitesse();// Destructeur

signals:
    void changerVitesse(float temps);//Signal envoyé a lecteur

private:
    Ui::RegleurVitesse* ui;
private slots:
    void confirmerVitesse();// Boutton OK qui emet le signal


};

#endif // REGLEURVITESSE_H
