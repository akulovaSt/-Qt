#ifndef STARLIST_H
#define STARLIST_H


#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "star.h"

class StarList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* starModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Star> listOfStars; // непосредственно данные
    QAbstractListModel *getModel();

public:
    StarList(QObject *parent = nullptr);
    ~StarList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            group = Qt::DisplayRole + 1,
            size = Qt::DisplayRole + 2,
            distance = Qt::DisplayRole + 3,
            coordinates = Qt::DisplayRole + 4
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE QString count(const QString& textFindSize);
    Q_INVOKABLE void edit(const QString& nameStar, const QString& groupStar, const QString& sizeStar, const QString& distanceStar, const QString& coordinatesStar, const int index);
};

#endif // STARLIST_H
