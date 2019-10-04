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
#include <iostream>

enum Burst{Red,Green,Yellow};



struct CurrentProperties{
    ButtonStore* intensityButtons;
    bool selectButton;
    bool ASPButton;
    bool masterButton;
    int masterIntensity;
    BurstTimeIndicator burstTime;
    //TODO currentTime
    //TODO timer
    //TODO timer color
};

struct Workout{
    std::list<std::pair<int,CurrentProperties*>> intensitiesByTime;
};

class ExerciseViewController: public ExerciseViewDelegate
{
private:
    ViewContent viewContentFromCurrentData() const;
    BaseExerciseView* view;
    CurrentProperties* currentViewProperties;
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

    void printCurrentProperties() const;

};

#endif // EXERCISEVIEWCONTROLLER_H
