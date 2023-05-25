#ifndef REGLEURVITESSE_H
#define REGLEURVITESSE_H

#include <QDialog>

namespace Ui {
class RegleurVitesse;
}

class RegleurVitesse : public QDialog
{
    Q_OBJECT

public:
    explicit RegleurVitesse(QWidget *parent, float temps);
    ~RegleurVitesse();

signals:
    void changerVitesse(float temps);

private:
    Ui::RegleurVitesse* ui;
private slots:
    void confirmerVitesse();


};

#endif // REGLEURVITESSE_H
