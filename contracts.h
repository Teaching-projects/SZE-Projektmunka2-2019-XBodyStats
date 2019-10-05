#ifndef CONTRACTS_H
#define CONTRACTS_H
#include <qstring.h>
#include <iostream>
//TODO implement these

enum Burst{Red,Green,Yellow};

enum StartButtonState{Start, Pause};

struct MuscleButtonProperties{
    bool isPressed;
    int buttonId;
    QString percent;

    void printContent(){
        std::cout << "button "<<buttonId << " ispressed: "<< isPressed << " percent "<< percent.toUtf8().constData() << std::endl;
    }
};

struct MasterButton{
    bool isVisible;
    bool isPressed;
    QString percent;
};

struct BurstTimeIndicator{
    QString time;
    int color;
};

// View will be displayed directly by View
struct ViewContent  {
   MuscleButtonProperties *buttons;
   bool selectButtonPressed;
   bool ASPButton;
   QString clock;
   BurstTimeIndicator timeIndicator;
   MasterButton masterButton;
   StartButtonState startButtonState;
   //int slideValue; only if needed
};

// Will be used in DataMining constructor acquired from Model
struct ModelData{

};


#endif // CONTRACTS_H
