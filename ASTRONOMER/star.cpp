#include "star.h"

Star::Star(QString ID, QString Name, QString Group, QString Size, QString Distance, QString Coordinates, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    group = Group;
    size = Size;
    distance = Distance;
    coordinates = Coordinates;
}



void Star::SetID(QString ID)
{
    id = ID;
}
void Star::SetName(QString Name)
{
    name = Name;
}
void Star::SetGroup(QString Group)
{
    group = Group;
}
void Star::SetSize(QString Size)
{
    size = Size;
}
void Star::SetDistance(QString Distance)
{
    distance = Distance;
}
void Star::SetCoordinates(QString Coordinates)
{
    coordinates = Coordinates;
}


QString Star::ID()
{
    return id;
}
QString Star::Name()
{
    return name;
}
QString Star::Group()
{
    return group;
}
QString Star::Size()
{
    return size;
}
QString Star::Distance()
{
    return distance;
}
QString Star::Coordinates()
{
    return coordinates;
}



QStringList Star::GetGroups()
{
    QStringList value;
    value.append("Лев");
    value.append("Лира");
    value.append("Орион");
    value.append("Лебедь");
    value.append("Гидра");
    return value;
}

 Star::~Star()
{
}
