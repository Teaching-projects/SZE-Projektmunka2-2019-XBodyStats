#include "exerciseviewcontroller.h"

ExerciseViewController::ExerciseViewController(BaseExerciseView* view)
{
    this->view = view;
}

ExerciseViewController::~ExerciseViewController()
{
    delete this->currentViewProperties;
}

void ExerciseViewController::muscleButtonOnPress(int buttonId)
{

}

void ExerciseViewController::mainButtonOnPress(bool direction)
{

}

void ExerciseViewController::sliderChanged(int value)
{

}

void ExerciseViewController::selectButtonPressed()
{

}

void ExerciseViewController::APSButtonPressed()
{

}

void ExerciseViewController::masterButtonPressed()
{

}

bool ExerciseViewController::canIntensityChange()
{
    if(this->currentViewProperties->ASPButton){
        return true;
    }else if (this->currentViewProperties->burstTime.color == Burst::Green){
        return false;
    }else{
        return true;
    }
}

ViewContent ExerciseViewController::viewContentFromCurrentData() const
{

}
