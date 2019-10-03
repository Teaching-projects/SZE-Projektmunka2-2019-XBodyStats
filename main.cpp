#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "model.h"
#include "datamining.h"
#include "exerciseviewcontroller.h"
#include "baseexerciseview.h"
#include "datamining.h"

using namespace std;

void printResult(string result, bool toFile){

    if (toFile){
        //TODO generate new  unique name for the file
        ofstream of("tempName");
        of << result;
    }else{
        cout << result;
    }
}

void closing(Model* model, DataMining* dataMining){

    delete model;
    delete dataMining;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ExerciseViewController* viewController= new ExerciseViewController(nullptr);

    //Model* model = new Model();
    //DataMining* dataMining = new DataMining(model->getData());

    //TODO Create ExerciseViewController -> create ExerciseView

    //dataMining->analyzeData();
    //printResult(*dataMining->getResult(), false);

    //closing(model, dataMining);

    return a.exec();
}
