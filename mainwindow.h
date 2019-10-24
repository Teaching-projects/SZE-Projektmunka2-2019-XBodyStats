#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "exerciseviewdelegate.h"
#include "baseexerciseview.h"
#include "contracts.h"
#include <vector>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public BaseExerciseView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ExerciseViewDelegate* delegate;

    void display(ViewContent* viewContent);

private slots:

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_master_clicked();

    void on_starbutton_clicked();

    void on_asp_clicked();

    void on_pozitive_clicked();

    void on_negative_clicked();

    void on_select_clicked();

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    std::vector<QLabel*> labels;
    std::vector<QPushButton*> buttons;
    int getId(QObject *)const;
    void setup();

};

#endif // MAINWINDOW_H
