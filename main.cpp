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
#include "filehandler.h"
#include "Algorithm.h"
#include "generator.h"
#include "selectrate.h"
#include "slideorbutton.h"
#include "startenddifferent.h"
#include "startvoltage.h"
#include "voltagerate.h"
#include "masterallrate.h"
#include "masterrate.h"
#include "algorithmqueue.h"

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
    MainWindow window;
    window.show();
    AlgorithmParams* params = new AlgorithmParams;
    if(argc >=5){
        params->minage = atoi(argv[1]);
        params->maxage = atoi(argv[2]);
        params->sex = atoi(argv[3]);
        params->minbmi = atoi(argv[4]);
        params->maxbmi = atoi(argv[5]);
    }

    Generator* gen = new Generator;
    auto test = gen->generateModels();

    AlgorithmQueue* queue = new AlgorithmQueue(test, params);
    delete queue;

    FileHandler::getInstance().writeToFile();

/*
    Algorithm* s = new StartVoltage(test);
    //delete s;

    Algorithm* s1 = new SelectRate(test);
    //delete s1;

    Algorithm* s2 = new SlideOrButton(test);
    //delete s2;

    Algorithm* s3 = new VoltageRate(test);
    //delete s3;

    Algorithm* s4 = new StartEndDifferent(test);
    //delete s4;

    Algorithm* s5 = new MasterAllRate(test);
    //delete s5;

    Algorithm* s6 = new MasterRate(test);
    delete s6;
*/


    ExerciseViewController* viewController= new ExerciseViewController(&window);
    window.delegate = viewController;

    //Model* model = new Model();
    //DataMining* dataMining = new DataMining(model->getData());

    //TODO Create ExerciseViewController -> create ExerciseView

    //dataMining->analyzeData();
    //printResult(*dataMining->getResult(), false);

    //closing(model, dataMining);
    //exit(EXIT_FAILURE);
    return a.exec();
}
