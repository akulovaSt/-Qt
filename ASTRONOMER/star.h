#ifndef STAR_H
#define STAR_H
#include "QString"
#include <QObject>

class Star: public QObject
{
    Q_OBJECT

public:
    Star(QString ID, QString Name, QString Group, QString Size, QString Distance, QString Coordinates, QObject *parent = nullptr );
    virtual ~Star();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetGroup(QString Group);
    void SetSize(QString Size);
    void SetDistance(QString Distance);
    void SetCoordinates(QString Coordinates);

    QString ID();
    QString Name();
    QString Group();
    QString Size();
    QString Distance();
    QString Coordinates();
    static QStringList GetGroups();
private:
    QString id;
    QString name;
    QString group;
    QString size;
    QString distance;
    QString coordinates;
};

#endif // STAR_H
