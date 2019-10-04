#include "exerciseviewcontroller.h"
#define PLUS true
#define MINUS false

#define ON true
#define OFF false

ExerciseViewController::ExerciseViewController(BaseExerciseView* view)
{
    this->view = view;
    this->currentViewProperties = new CurrentProperties();
    this->currentViewProperties->intensityButtons = new ButtonStore();
}

ExerciseViewController::~ExerciseViewController()
{
    delete this->currentViewProperties->intensityButtons;
    delete this->currentViewProperties;
}

void ExerciseViewController::muscleButtonOnPress(int buttonId)
{
    this->currentViewProperties->intensityButtons->buttonSelected(buttonId,this->currentViewProperties->selectButton);

    if(this->currentViewProperties->masterButton == ON){
        this->currentViewProperties->masterButton = OFF;
    }
}

void ExerciseViewController::mainButtonOnPress(bool direction)
{
    if(this->currentViewProperties->masterButton){
        if(direction == PLUS){
            this->currentViewProperties->masterIntensity++;
        }else{
            this->currentViewProperties->masterIntensity--;
        }
    }else{
        this->currentViewProperties->intensityButtons->updateIntensities(direction);
    }
}

void ExerciseViewController::sliderChanged(int value)
{
    this->currentViewProperties->intensityButtons->setButtonValues(value);
}

void ExerciseViewController::selectButtonPressed()
{
    this->currentViewProperties->selectButton = !this->currentViewProperties->selectButton;
}

void ExerciseViewController::APSButtonPressed()
{
    this->currentViewProperties->ASPButton = !this->currentViewProperties->ASPButton;
}

void ExerciseViewController::masterButtonPressed()
{
    this->currentViewProperties->masterButton = ON;
    this->currentViewProperties->intensityButtons->deselectAll();
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
    ViewContent toReturn;
    toReturn.ASPButton = this->currentViewProperties->ASPButton;
    toReturn.masterButton.isPressed = this->currentViewProperties->masterButton;
    toReturn.masterButton.percent = QString(this->currentViewProperties->masterIntensity);
    toReturn.selectButtonPressed = this->currentViewProperties->selectButton;
    toReturn.clock = QString("tmp");
    toReturn.timeIndicator.color = Green;
    toReturn.timeIndicator.time = QString("tmp");
    toReturn.buttons = this->currentViewProperties->intensityButtons->getMuscleButtonProperties();

    return toReturn;
}

void ExerciseViewController::printCurrentProperties() const
{

}
