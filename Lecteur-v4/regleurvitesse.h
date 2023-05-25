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
    explicit RegleurVitesse(QWidget *parent = nullptr);
    ~RegleurVitesse();

private:
    Ui::RegleurVitesse *ui;
};

#endif // REGLEURVITESSE_H
