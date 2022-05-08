#include "starlistsql.h"
#include "QObject"

starListSQL::starListSQL(QObject *parent) :
    QSqlQueryModel(parent)
{
    db = QSqlDatabase::addDatabase("QPSQL", "myConnection");

    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("Yfcnfcmz1736");
    db.setDatabaseName("Star");

     _isConnectionOpen = true;

    if(!db.open())
    {
        qDebug() << db.lastError().text();
        _isConnectionOpen = false;
    }

    QString m_schema = QString( "CREATE TABLE IF NOT EXISTS Star (Id SERIAL PRIMARY KEY, NameOfStar text, GroupOfStar text, SizeOfStar text, DistanceOfStar text, CoordinatesOfStar text);" );
    QSqlQuery qry(m_schema, db);

    if( !qry.exec() )
    {
    }

    refresh();
}

QSqlQueryModel* starListSQL::getModel(){
    return this;
}
bool starListSQL::isConnectionOpen(){
    return _isConnectionOpen;
}
QHash<int, QByteArray> starListSQL::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "NameOfStar";
    roles[Qt::UserRole + 2] = "GroupOfStar";
    roles[Qt::UserRole + 3] = "SizeOfStar";
    roles[Qt::UserRole + 4] = "DistanceOfStar";
    roles[Qt::UserRole + 5] = "CoordinatesOfStar";
    roles[Qt::UserRole + 6] = "Id_star";

    return roles;
}


QVariant starListSQL::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if(role < Qt::UserRole-1)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

const char* starListSQL::SQL_SELECT =
        "SELECT NameOfStar, GroupOfStar, SizeOfStar, DistanceOfStar, CoordinatesOfStar, Id"
        " FROM Star";

void starListSQL::refresh()
{
    this->setQuery(starListSQL::SQL_SELECT,db);
}

void starListSQL::add(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar){

    QSqlQuery query(db);
    QString strQuery= QString("INSERT INTO Star (NameOfStar, GroupOfStar, SizeOfStar, DistanceOfStar, CoordinatesOfStar) VALUES ('%1', '%2', '%3', '%4', '%5')")
            .arg(nameStar)
            .arg(groupStar)
            .arg(sizeStar)
            .arg(distanceStar)
            .arg(coordinatesStar);
    query.exec(strQuery);

    refresh();
}

void starListSQL::edit(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar, const int Id_star){

    QSqlQuery query(db);
    QString strQuery= QString("UPDATE Star SET NameOfStar = '%1', GroupOfStar = '%2', SizeOfStar = '%3', DistanceOfStar = '%4', CoordinatesOfStar = '%5' WHERE Id = %6")
            .arg(nameStar)
            .arg(groupStar)
            .arg(sizeStar)
            .arg(distanceStar)
            .arg(coordinatesStar)
            .arg(Id_star);
    query.exec(strQuery);

    refresh();

}
void starListSQL::del(const int Id_star){

    QSqlQuery query(db);
    QString strQuery= QString("DELETE FROM Star WHERE Id = %1")
            .arg(Id_star);
    query.exec(strQuery);

    refresh();
}

