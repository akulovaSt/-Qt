#include "starlist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

StarList::StarList(QObject* parent):QAbstractListModel(parent)
{
    add("Бетельгейзе", "Орион", "200", "495 св. лет", "+7ч 24м 25с");
    add("Вега", "Лира", "30", "25 св. лет", "+38ч 47м 1с");
    add("Денеб", "Лебедь", "10", "1500 св. лет", "+45ч 16м 49с");
}

StarList::~StarList()
{

}

int StarList::rowCount(const QModelIndex&) const
{
    return listOfStars.size();
}

QVariant StarList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfStars.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfStars.at(index.row()).getName());
                case group:
                    return QVariant(listOfStars.at(index.row()).getGroup());
                case size:
                    return QVariant(listOfStars.at(index.row()).getSize());
                case distance:
                    return QVariant(listOfStars.at(index.row()).getDistance());
                case coordinates:
                    return QVariant(listOfStars.at(index.row()).getCoordinates());

                default:
                    return QVariant();
            }
    }
}

QHash<int, QByteArray> StarList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfStar";
    roles[group] = "groupOfStar";
    roles[size] = "sizeOfStar";
    roles[distance] = "distanceOfStar";
    roles[coordinates] = "coordinatesOfStar";
    return roles;
}

void StarList::add(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar){
    Star star;
    star.setName(nameStar);
    star.setGroup(groupStar);
    star.setSize(sizeStar);
    star.setDistance(distanceStar);
    star.setCoordinates(coordinatesStar);

    beginInsertRows(QModelIndex(),listOfStars.size(),listOfStars.size());
    listOfStars.append(star);  //добавление в конец списка
    endInsertRows();
}

QAbstractListModel* StarList::getModel(){
    return this;
}

void StarList::del(const int index){

     if (index >= 0 && index < listOfStars.size())
     {
    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
         listOfStars.removeAt(index);
         endRemoveRows();
     }
     else qDebug() << "Error index";
}

QString StarList::count(const QString& textFindSize){
    int count = 0;

    for(int i = 0; i < listOfStars.size(); i++)
        if(listOfStars[i].getSize().toInt() > textFindSize.toInt())//введенное значение сравнивается с табличным
            count++;

    QString c = QString::number(count);
    return c;
}

void StarList::edit(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar, const int index) {
     if(index >= 0 && index < listOfStars.size() )
     {
         auto& currentStar = listOfStars[index];
         if (currentStar.getName().compare(nameStar)!=0 || currentStar.getGroup() != groupStar || currentStar.getSize() != sizeStar
             || currentStar.getDistance() != distanceStar || currentStar.getCoordinates() != coordinatesStar)
        {
            currentStar.setName(nameStar);
            currentStar.setGroup(groupStar);
            currentStar.setSize(sizeStar);
            currentStar.setDistance(distanceStar);
            currentStar.setCoordinates(coordinatesStar);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfStars[index].getSize();
        }
     }
      else qDebug() << "Error index";
}

