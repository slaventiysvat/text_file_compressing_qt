#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
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

    //QTime time_m(int num1,int num2,int num3): num1{0}, num2{0}, num3{0} {};                // n == 00:00:00
    //QTime time_m;

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_progressBar_valueChanged(int value, QTime time);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
