#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>

#define DATABASE_NAME "SAE_BD"
#define CONNECT_TYPE "QODBC"
#define USERNAME "scurran_bd"
#define HOST_NAME "lakartxela.iutbayonne.univ-pau.fr"
#define PORT 3306
class Database
{
public:
    Database(); //Constructeur
    bool openDataBase(); // Ouvre la base de donnée, retourne si Vrai si la base de donnée a été ouverte
    void closeDataBase(); // ferme la base de donnée

private:
    QSqlDatabase mydb; // base de donnée
};

#endif // DATABASE_H
