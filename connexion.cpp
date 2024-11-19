#include "connexion.h"
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); // DB attribut de la classe connection
    db.setDatabaseName("Source_projet2A");
    db.setUserName("ghaith"); // inserer nom de l'utilisateur
    db.setPassword("ghaith"); // inserer mot de passe de cet utilisateur

    if (db.open())
        test = true;

    return test;
}
