#include "buttonmodel.h"

ButtonStore::ButtonStore()
{
    for(int i = 0;i< 11;i++){
        ButtonModel* model = new ButtonModel;
        model->id = i;
        model->intensity = 0;
        model->isPressed = false;
        buttons.push_back(model);
    }
}

ButtonStore::~ButtonStore()
{
    for(int i=0;i< 11;i++){
        delete buttons[i];
    }
}

void ButtonStore::updateIntensities(bool direction)
{
    for(auto& button: buttons){
        if(button->isPressed){
            if(direction == PLUS){
                button->intensity++;
            }else{
                button->intensity--;
            }
        }
    }
}

void ButtonStore::updateIntensity(int id, bool direction)
{
     for(auto& button: buttons){
         if(button->id == id){
             if(direction == PLUS){
                 button->intensity++;
             }else{
                 button->intensity--;
             }
             return;
         }
     }
}

void ButtonStore::buttonSelected(int id, bool multiple)
{
    if(!multiple){
        this->deselectAll();
    }

    for(auto& button: buttons){
        if(button->id == id){
            button->isPressed = true;
            return;
        }
    }
}

void ButtonStore::deselectAll()
{
    for(auto& button: buttons){
        button->isPressed = false;
    }
}

void ButtonStore::setButtonValues(int value)
{
    for(auto& button: buttons){
        if(button->isPressed == true){
           button->intensity = value;
        }
    }
}

MuscleButtonProperties* ButtonStore::getMuscleButtonProperties()
{
    MuscleButtonProperties* toReturn = new MuscleButtonProperties[11];

    for(int i=0;i<11;i++){
        toReturn[i].buttonId = buttons[i]-> id;
        toReturn[i].isPressed = buttons[i]-> isPressed;
        toReturn[i].percent = QString(buttons[i]->intensity);
    }

    return toReturn;
}
