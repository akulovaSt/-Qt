#include "star.h"

Star::Star()
{

}

void Star::setID(const QString ID)
{
    id = ID;
}
void Star::setName(const QString Name)
{
    name = Name;
}
void Star::setGroup(const QString Group)
{
    group = Group;
}
void Star::setSize(const QString Size)
{
    size = Size;
}
void Star::setDistance(const QString Distance)
{
    distance = Distance;
}
void Star::setCoordinates(const QString Coordinates)
{
    coordinates = Coordinates;
}

QString Star::getID() const
{
    return id;
}
QString Star::getName() const
{
    return name;
}
QString Star::getGroup() const
{
    return group;
}
QString Star::getSize() const
{
    return size;
}
QString Star::getDistance() const
{
    return distance;
}
QString Star::getCoordinates() const
{
    return coordinates;
}

 Star::~Star()
{
}
