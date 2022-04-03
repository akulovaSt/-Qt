#include "editstardialog.h"
#include "star.h"

EditStarDialog::EditStarDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editGroup = new QComboBox();
    editSize = new QLineEdit();
    editDistance = new QLineEdit();
    editCoordinates = new QLineEdit();
    QStringList groups = Star::GetGroups();

    foreach  (QString gr, groups)
    {
        editGroup->addItem(gr);
    }

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Созвездие"),3,1);
    mainLayout->addWidget(editGroup,3,2);
    mainLayout->addWidget(new QLabel("Видимая звездная величина"),4,1);
    mainLayout->addWidget(editSize,4,2);
    mainLayout->addWidget(new QLabel("Расстояние от Земли"),5,1);
    mainLayout->addWidget(editDistance,5,2);
    mainLayout->addWidget(new QLabel("Координаты на небосклоне"),6,1);
    mainLayout->addWidget(editCoordinates,6,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о звезде");

    int gx = 100;
    int gy = 100;

    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();
    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditStarDialog::id() const
{
    return editID->text();
}
QString EditStarDialog::name() const
{
    return editName->text();
}
QString EditStarDialog::group() const
{
    return editGroup->currentText();
}
QString EditStarDialog::size() const
{
    return editSize->text();
}
QString EditStarDialog::distance() const
{
    return editDistance->text();
}
QString EditStarDialog::coordinates() const
{
    return editCoordinates->text();
}

void EditStarDialog::SetUpDialog(QString id, QString name, QString group, QString size, QString distance, QString coordinates)
{
    editID->setText(id);
    editName->setText(name);

    int ind = editGroup->findText(group);

    if (ind>=0)
    {
        editGroup->setCurrentIndex(ind);
    }

    editSize->setText(size);
    editDistance->setText(distance);
    editCoordinates->setText(coordinates);

}
