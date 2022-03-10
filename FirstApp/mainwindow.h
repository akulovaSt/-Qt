#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:    

    void slotLineEdit1();
    void slotLineEdit3();
    void slotLineEdit2();

    void slotMinus();
    void slotPlus();

    void slotLineEdit4();


private:
    Ui::MainWindow *ui;

    int num, min, max, adding;
};
#endif // MAINWINDOW_H
