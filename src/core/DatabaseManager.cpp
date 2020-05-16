#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager(const QString& path)
    : mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase),
    pictureDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);

    bool openStatus = mDatabase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

  albumDao.init();
  pictureDao.init();
}

DatabaseManager& DatabaseManager::instance() {
  static DatabaseManager mDatabase;
  return mDatabase;
}

DatabaseManager::~DatabaseManager() {
  mDatabase->close();
  delete mDatabase;
}


void DatabaseManager::debugQuery(const QSqlQuery& query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:"  << query.lastQuery();
    } else {
       qWarning() << "Query KO:" << query.lastError().text();
       qWarning() << "Query text:" << query.lastQuery();
    }
}
