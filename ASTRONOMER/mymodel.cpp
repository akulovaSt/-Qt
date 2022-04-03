#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Star* std1 = new Star("101","Бетельгейзе", "Орион", "от +0,2 до +1,2m", "от 495 до 640 св. лет", "+07ч 24м 25с", this);
    Star* std2 = new Star("102","Вега", "Лира", "+0,03m", "25 св. лет", "+38ч 47м 01,291с", this);
    Star* std3 = new Star("103","Денеб", "Лебедь", "+1,25m", "1500 св. лет", "+45ч 16м 49с", this);
    AddStar(std1);
    AddStar(std2);
    AddStar(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
    return stars.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Star* std = stars.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Group();}
        else if (index.column() == 3){Value = std->Size();}
        else if (index.column() == 4){Value = std->Distance();}
        else if (index.column() == 5){Value = std->Coordinates();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Созвездие");
            case 3:
                return QString("Видимая звездная величина");
            case 4:
                return QString("Расстояние от Земли");
            case 5:
                return QString("Координаты на небосклоне");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Star* std = stars.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetGroup(value.toString());}
        else if (index.column() == 3){std->SetSize(value.toString());}
        else if (index.column() == 4){std->SetDistance(value.toString());}
        else if (index.column() == 5){std->SetCoordinates(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}


void MyModel::AddStar(Star* star)
{
    beginInsertRows(QModelIndex(),stars.size(),stars.size());
    stars.append(star);
    endInsertRows();
}

void MyModel::DeleteStar(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    stars.removeAt(row);
    endRemoveRows();
}

