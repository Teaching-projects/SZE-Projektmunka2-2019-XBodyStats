#ifndef EXERCISEVIEWCONTROLLER_H
#define EXERCISEVIEWCONTROLLER_H
#include "exerciseviewdelegate.h"
#include "baseexerciseview.h"
#include "contracts.h"
#include <list>
#include <time.h>

enum Burst{Red,Green,Yellow};

struct Intensities{
    int quadriceps;
    int hamstrings;
    int glutes;
    int abs;
    int lowerBack;
    int back;
    int trapezius;
    int pectoral;
    int arms;
    int shoulders;
    int calves;
};

struct Workout{
    std::list<std::pair<int,Intensities*>> intensitiesByTime;
};

struct CurrentProperties{
    Intensities intensity;
    bool* buttons;
    bool selectButton;
    bool ASPButton;
    bool master;
    BurstTimeIndicator burstTime;
    //TODO currentTime
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

};

#endif // EXERCISEVIEWCONTROLLER_H
