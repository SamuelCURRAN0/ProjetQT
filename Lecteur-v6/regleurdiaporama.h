#ifndef REGLEURDIAPORAMA_H
#define REGLEURDIAPORAMA_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class RegleurDiaporama;
}

class RegleurDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit RegleurDiaporama(QWidget *parent = nullptr);// Constructeur
    ~RegleurDiaporama();// Destructeur

private:
    Ui::RegleurDiaporama *ui; // Form du RegleurDiapo

signals:
    void changerDiapo(unsigned int numDiapo); // Signal reçu par Lecteur qui charge un autre diaporama
public slots:
    void confirmerDiapo();//Boutton OK de l'ui cliquer allume le signal
};

#endif // REGLEURDIAPORAMA_H
