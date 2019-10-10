#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "exerciseviewdelegate.h"
#include "baseexerciseview.h"
#include "contracts.h"

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

    void display(ViewContent* v);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
