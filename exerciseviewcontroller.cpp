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
    this->currentViewProperties->currentTime = 1200;
    this->currentViewProperties->burstTime = 4;
    this->currentViewProperties->burstColour = Green;
    this->currentViewProperties->masterIntensity = 0;
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
    this->view->display(this->viewContentFromCurrentData());
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
    this->view->display(this->viewContentFromCurrentData());
}

void ExerciseViewController::sliderChanged(int value)
{   if(this->currentViewProperties->masterButton){
        this->currentViewProperties->masterIntensity = value;
    }else{
        this->currentViewProperties->intensityButtons->setButtonValues(value);
    }
    this->view->display(this->viewContentFromCurrentData());
}

void ExerciseViewController::selectButtonPressed()
{
    this->currentViewProperties->selectButton = !this->currentViewProperties->selectButton;
    this->view->display(this->viewContentFromCurrentData());
}

void ExerciseViewController::APSButtonPressed()
{
    this->currentViewProperties->ASPButton = !this->currentViewProperties->ASPButton;
    this->view->display(this->viewContentFromCurrentData());
}

void ExerciseViewController::masterButtonPressed()
{
    this->currentViewProperties->masterButton = ON;
    this->currentViewProperties->intensityButtons->deselectAll();
    this->view->display(this->viewContentFromCurrentData());
}

bool ExerciseViewController::canIntensityChange()
{
    if(this->currentViewProperties->ASPButton){
        return true;
    }else if (this->currentViewProperties->burstColour == Burst::Green){
        return false;
    }else{
        return true;
    }
}

ViewContent* ExerciseViewController::viewContentFromCurrentData() const
{
    ViewContent* toReturn = new ViewContent;
    toReturn->ASPButton = this->currentViewProperties->ASPButton;
    toReturn->masterButton.isPressed = this->currentViewProperties->masterButton;
    toReturn->masterButton.percent = QString::number(this->currentViewProperties->masterIntensity) + QString(" %");
    toReturn->selectButtonPressed = this->currentViewProperties->selectButton;
    toReturn->clock = QString::number(this->currentViewProperties->currentTime);
    toReturn->timeIndicator.color = this->currentViewProperties->burstColour;
    toReturn->timeIndicator.time = QString::number(this->currentViewProperties->burstTime);
    toReturn->buttons = this->currentViewProperties->intensityButtons->getMuscleButtonProperties();
    toReturn->startButtonState = this->currentViewProperties->startButtonState;

    return toReturn;
}

Burst ExerciseViewController::changeColour()
{
    if(this->currentViewProperties->burstColour == Green){
        return Red;
    }
    if(this->currentViewProperties->burstColour == Red){
        return Green;
    }
    return Yellow;
}

void ExerciseViewController::manageTime(){

    for(;;){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(this->currentViewProperties->currentTime == 0){
            break;
        }else{
            this->currentViewProperties->currentTime--;
        }

        if(this->currentViewProperties->burstTime == 0){
            this->currentViewProperties->burstTime = 4;
            this->currentViewProperties->burstColour = this->changeColour();
        }else{
            this->currentViewProperties->burstTime--;
        }
        this->view->display(this->viewContentFromCurrentData());
    }
}

void ExerciseViewController::startButtonPressed()
{
    std::thread(&ExerciseViewController::manageTime, this).detach();
}

void ExerciseViewController::printCurrentProperties() const
{

}
