#ifndef MODIFIERDIAPORAMA_H
#define MODIFIERDIAPORAMA_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ModifierDiaporama;
}

class ModifierDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierDiaporama(QWidget *parent, QString intituleDiapo, QString intituleImage, QString cheminImage, unsigned int rangImage);
    ~ModifierDiaporama();

private:
    Ui::ModifierDiaporama *ui;

signals:
    void modifierDiaporama(QString intituleDiapo, QString intituleImage, QString cheminImage, unsigned int rangImage); //Signal envoyé a lecteur
public slots:
    void confirmerModification();//Boutton OK de l'ui cliquer allume le signal

};

#endif // MODIFIERDIAPORAMA_H
