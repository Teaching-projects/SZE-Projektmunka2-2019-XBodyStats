#ifndef EXERCISEVIEWCONTROLLER_H
#define EXERCISEVIEWCONTROLLER_H

#define ON true
#define OFF false

#include "exerciseviewdelegate.h"
#include "baseexerciseview.h"
#include "contracts.h"
#include "buttonmodel.h"
#include <qstring.h>
#include <vector>
#include <list>
#include <time.h>
#include <thread>
#include <chrono>
#include <iostream>



struct CurrentProperties{
    ButtonStore* intensityButtons;
    bool selectButton;
    bool ASPButton;
    bool masterButton;
    int masterIntensity;
    int burstTime;
    Burst burstColour;
    int currentTime;
    StartButtonState startButtonState;
};

struct Workout{
    std::list<std::pair<int,CurrentProperties*>> intensitiesByTime;
};

class ExerciseViewController: public ExerciseViewDelegate
{
private:
    ViewContent* viewContentFromCurrentData() const;
    BaseExerciseView* view;
    CurrentProperties* currentViewProperties;
    void manageTime();
    Burst changeColour();
public:
    ExerciseViewController(BaseExerciseView* view);
    ~ExerciseViewController();
    void muscleButtonOnPress(int buttonId) override;
    void mainButtonOnPress(bool direction) override;
    void sliderChanged(int value) override;
    void selectButtonPressed() override;
    void APSButtonPressed() override;
    void masterButtonPressed() override;
    bool canIntensityChange() override;
    void startButtonPressed() override;


    void printCurrentProperties() const;
    //TODO implement time management
};

#endif // EXERCISEVIEWCONTROLLER_H
