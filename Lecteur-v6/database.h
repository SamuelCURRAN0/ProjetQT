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
    Database();
    bool openDataBase();
    void closeDataBase();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
