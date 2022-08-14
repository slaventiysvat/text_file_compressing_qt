#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTime>
#include "input_data.h"
#include "count_binary_data.h"

extern QVector<char> non_binary_ref;
extern QVector<char> binary_data;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->label->setText("Choosed File");

}


void MainWindow::on_pushButton_2_clicked()
{



}


//static int  value_in = 0;

void MainWindow::on_pushButton_3_clicked()
{

    QVector<int> not_binary_data;
    QVector<int> diff(non_binary_ref.size(), 0);


       count_binary_data bData;
       float step = 100.f / static_cast<float>( binary_data.size());
       float step_init = 0.0f;
       volatile int istep = 0;
       int k = 0;

       for (int i = 0; i < binary_data.size(); i++) {


           data_definition status = bData.new_count(binary_data.at(i));

           if (status == data_definition::DATA_CHANGED) {

               not_binary_data.push_back(bData.get_num_size());
               diff[k] = not_binary_data.at(k) - non_binary_ref.at(k);
               k++;
           }

           //Progress Bar processing
           step_init = step_init + step;
           if (static_cast<int>(step_init) >= 1){

               istep = istep + 1;
               ui->progressBar->setValue(istep);
               ui->progressBar->update();
               step_init = step_init - 1.0f;//not zero but we safe 0.01% e.t.c
               //QThread::msleep(10);

           }

       }

}


void MainWindow::on_progressBar_valueChanged(int value, QTime time)
{

    ui->label_3->setText("Value Changed Time");
    ui->label_2->setText("Value Changed Time");
}

