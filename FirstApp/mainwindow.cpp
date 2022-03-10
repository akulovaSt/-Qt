#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLineEdit"
#include "QMessageBox"
#include "QIntValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   ui->lineEdit_1->setValidator( new QIntValidator);
   ui->lineEdit_2->setValidator( new QIntValidator);
   ui->lineEdit_3->setValidator( new QIntValidator);
   ui->lineEdit_4->setValidator( new QIntValidator);

    num=0;
    min=0;
    max=100;
    adding=1;

connect(ui->lineEdit_1, SIGNAL (editingFinished()), this, SLOT (slotLineEdit1()));
connect(ui->lineEdit_3, SIGNAL (editingFinished()), this, SLOT (slotLineEdit3()));
connect(ui->lineEdit_2, SIGNAL (editingFinished()), this, SLOT (slotLineEdit2()));

connect(ui->pushButton_2, SIGNAL (clicked()), this, SLOT (slotMinus()));
connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (slotPlus()));

connect(ui->lineEdit_4, SIGNAL (editingFinished()), this, SLOT (slotLineEdit4()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotLineEdit1()
{
    num = ui -> lineEdit_1 -> text().toInt();
    if (num<=max && num>=min)
        ui->progressBar->setValue(num);
    else
        QMessageBox::about(this, "Неверный ввод значений", "Изменяемое число должно входить в указвнный диапазон!");
}


void MainWindow::slotLineEdit3()
{
    min = ui -> lineEdit_3 -> text().toInt();
    if (min>max)
        QMessageBox::about(this, "Неверный ввод значений", "Минимальное значение не должно превышать максимальное!");
    if (num>max || num<min)
        QMessageBox::about(this, "Неверный ввод значений", "Изменяемое число должно входить в указанный диапазон!");
    else
        ui->progressBar->setMinimum(min);
}


void MainWindow::slotLineEdit2()
{
    max = ui -> lineEdit_2 -> text().toInt();
    if (min>max)
        QMessageBox::about(this, "Неверный ввод значений", "Минимальное значение не должно превышать максимальное!");
    if (num>max || num<min)
        QMessageBox::about(this, "Неверный ввод значений", "Изменяемое число должно входить в указанный диапазон!");
    else
        ui->progressBar->setMaximum(max);
}

void MainWindow::slotMinus()
{
  num=num-adding;

  if(num>=min)
    ui->progressBar->setValue(num);
  else
    {
        QMessageBox::about(this, "Выход за границу значения", "Дальнейшее уменьшение невозможно!");
        num=num+adding;
    }
}


void MainWindow::slotPlus()
{
   num=num+adding;

   if(num<=max)
     ui->progressBar->setValue(num);
   else
     {
        QMessageBox::about(this, "Выход за границу значения", "Дальнейшее увеличение невозможно!");
        num=num-adding;
     }
}

void MainWindow::slotLineEdit4()
{
    adding = ui -> lineEdit_4 -> text().toInt();
}

