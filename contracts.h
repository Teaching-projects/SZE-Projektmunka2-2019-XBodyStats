#ifndef CONTRACTS_H
#define CONTRACTS_H
#include <qstring.h>
#include <qcolor.h>
#include <iostream>
#include <vector>
//TODO implement these

enum Burst{Red,Green,Yellow};

enum StartButtonState{Start, Pause, Resume};

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
    Burst color;
};

// View will be displayed directly by View
struct ViewContent  {
   MuscleButtonProperties *buttons;
   int sliderValue;
   bool selectButtonPressed;
   bool ASPButton;
   QString clock;
   BurstTimeIndicator timeIndicator;
   MasterButton masterButton;
   StartButtonState startButtonState;
   //int slideValue; only if needed
};


/**
 * Below lies the model data used for data mining
 */

enum Event {Button,Slider,Master};

enum Muscle {Quadriceps, Hamstring, Glutes, Abs, LowerBack, Back, Trapezius, Pectoral, Arms, Shoulders, Calves};

enum ExerciseType{Cardio, Weights};

struct MuscleModel{
    Muscle muscle;
    int percent;
    bool isSelected;
    Event* chagedWith;
};

struct MasterButtonModel{
    int percent;
};

struct ExerciseSecond{
    int time;
    std::vector<MuscleModel*> muscles;
    MasterButtonModel* master;
};

struct User{
    bool sex;
    int age;
    int weight;
    int height;
};

struct ModelData{
    std::string fileName;
    User user;
    ExerciseType type;
    std::vector<ExerciseSecond*> seconds;
};
#endif // CONTRACTS_H
