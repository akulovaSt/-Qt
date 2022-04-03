#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "groupdelegate.h"
#include "linedelegate.h"
#include "editstardialog.h"
#include "dialogdelegate.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);
    GroupDelegate* fdel = new GroupDelegate();
    lineDelegate* ldel = new lineDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,fdel);
    tableView->setItemDelegateForColumn(3,ddel);
    tableView->setItemDelegateForColumn(4,ldel);
    tableView->setItemDelegateForColumn(5,fdel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);



    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Добавить строку");
    QPushButton* pb2 = new QPushButton("Удалить строку");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);
    this->setGeometry(100, 100, 700, 300);


    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor(209,153,255));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditStarDialog* addDialog = new EditStarDialog(this);

    if (addDialog->exec() == QDialog::Accepted)
    {
        Star* st = new Star(addDialog->id(),addDialog->name(),addDialog->group(), addDialog->size(), addDialog->distance(), addDialog->coordinates(),this);
        myModel->AddStar(st);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteStar(selList.row());
}



