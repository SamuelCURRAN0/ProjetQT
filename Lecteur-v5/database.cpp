#include "database.h"

Database::Database()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setHostName(HOST_NAME);
    mydb.setPort(PORT);
    mydb.setDatabaseName(DATABASE_NAME);
    mydb.setUserName(USERNAME);
    mydb.setPassword(USERNAME);
}
bool Database::openDataBase()
{
    return mydb.open();
}
void Database::closeDataBase()
{
    mydb.close();
}
