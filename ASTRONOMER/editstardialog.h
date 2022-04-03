#ifndef EDITSTARDIALOG_H
#define EDITSTARDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "star.h"

class EditStarDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QComboBox* editGroup;
    QLineEdit* editSize;
    QLineEdit* editDistance;
    QLineEdit* editCoordinates;


public:
    EditStarDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString group() const;
    QString size() const;
    QString distance() const;
    QString coordinates() const;

    void SetUpDialog(QString id, QString name, QString group, QString size, QString distance, QString coordinates);
};

#endif // EDITSTARDIALOG_H
