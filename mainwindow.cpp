#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labels = std::vector<QLabel*>{
            ui->label_1,
            ui->label_2,
            ui->label_3,
            ui->label_4,
            ui->label_5,
            ui->label_6,
            ui->label_7,
            ui->label_8,
            ui->label_9,
            ui->label_10,
            ui->label_11,
            ui->label_12
    };
    buttons = std::vector<QPushButton*>{
            ui->pushButton_1,
            ui->pushButton_2,
            ui->pushButton_3,
            ui->pushButton_4,
            ui->pushButton_5,
            ui->pushButton_6,
            ui->pushButton_7,
            ui->pushButton_8,
            ui->pushButton_9,
            ui->pushButton_10,
            ui->pushButton_11,
            ui->pushButton_12
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::display(ViewContent *viewContent)
{
    for(unsigned int i=0;i<12;i++){
        labels[i]->setText(viewContent-> buttons[i].percent);
        ui->kisido->setText(viewContent->timeIndicator.time);
        ui->nagyido->setText(viewContent->clock);
        ui->master_Label->setText(viewContent->masterButton.percent);
    }
}

int MainWindow::getId(QObject *object) const{
    for(unsigned int i = 0; i < buttons.size(); i++){
        if(buttons[i] == object){
            return static_cast<int>(i);
        }
    }
    for(unsigned int i = 0; i < labels.size(); i++){
        if(labels[i] == object){
            return static_cast<int>(i);
        }
    }
    return -1;
}


void MainWindow::on_pushButton_8_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_9_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_10_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_11_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_12_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_2_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_3_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_4_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_7_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_1_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_5_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_pushButton_6_clicked()
{
    QObject* sender = QObject::sender();
    delegate->muscleButtonOnPress(getId(sender));
}

void MainWindow::on_master_clicked()
{
    delegate->masterButtonPressed();
}

void MainWindow::on_starbutton_clicked()
{
    delegate->startButtonPressed();
}

void MainWindow::on_asp_clicked()
{
    delegate->APSButtonPressed();
}

void MainWindow::on_pozitive_clicked()
{
    if(delegate->canIntensityChange() == false){
        return;
    }
    delegate->mainButtonOnPress(true);
}

void MainWindow::on_negative_clicked()
{
    if(delegate->canIntensityChange() == false){
        return;
    }
    delegate->mainButtonOnPress(false);
}

void MainWindow::on_select_clicked()
{
    delegate->selectButtonPressed();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    if(delegate->canIntensityChange() == false){
        return;
    }
    delegate->sliderChanged(position);
}
