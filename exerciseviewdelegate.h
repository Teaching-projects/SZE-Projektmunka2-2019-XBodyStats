#ifndef EXERCISEVIEWDELEGATE_H
#define EXERCISEVIEWDELEGATE_H
#include "baseexerciseview.h"
class BaseExerciseView;

//Delegate class inherited by ExerciseViewController
class ExerciseViewDelegate
{
public:
    ExerciseViewDelegate(){}
    virtual ~ExerciseViewDelegate(){}

    virtual void muscleButtonOnPress(int buttonId) = 0;
    virtual void mainButtonOnPress(bool direction) = 0;
    virtual void sliderChanged(int value) = 0;
    virtual void selectButtonPressed() = 0;
    virtual void APSButtonPressed() = 0;
    virtual void masterButtonPressed() = 0;
    virtual bool canIntensityChange() = 0;
    virtual void startButtonPressed() = 0;

    /* Will be added if needed
    virtual void optionsPressed() =0;
    */
};

#endif // EXERCISEVIEWDELEGATE_H
