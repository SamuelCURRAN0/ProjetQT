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
    explicit RegleurDiaporama(QWidget *parent = nullptr);
    ~RegleurDiaporama();

private:
    Ui::RegleurDiaporama *ui;

signals:
    void changerDiapo(unsigned int numDiapo);
public slots:
    void confirmerDiapo();
};

#endif // REGLEURDIAPORAMA_H
