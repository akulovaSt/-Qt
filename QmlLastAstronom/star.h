#ifndef STAR_H
#define STAR_H

#include "QString"
//#include <QObject>

class Star /*public QObject*/
{
    //Q_OBJECT

public:
    Star();
    virtual ~Star();
    void setID(const QString ID);
    void setName(const QString Name);
    void setGroup(const QString Group);
    void setSize(const QString Size);
    void setDistance(const QString Distance);
    void setCoordinates(const QString Coordinates);

    QString getID() const;
    QString getName() const;
    QString getGroup() const;
    QString getSize() const;
    QString getDistance() const;
    QString getCoordinates() const;

private:
    QString id;
    QString name;
    QString group;
    QString size;
    QString distance;
    QString coordinates;
};


#endif // STAR_H
