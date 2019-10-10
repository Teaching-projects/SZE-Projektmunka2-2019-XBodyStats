#include "buttonmodel.h"

ButtonStore::ButtonStore()
{
    for(int i = 0;i < 12;i++){
        ButtonModel* model = new ButtonModel;
        model->id = i;
        model->intensity = 0;
        model->isPressed = false;
        buttons.push_back(model);
    }
    selectedButtonCount = 0;
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
            bool state = !button->isPressed;

            if(state == true){
                selectedButtonCount++;
                button->isPressed = state;
            }else{
                if(selectedButtonCount > 1){
                    button->isPressed = state;
                    selectedButtonCount--;
                }
            }
//            button->isPressed = !button->isPressed;
//            if(button->isPressed){
//                selectedButtonCount++;
//            }else{
//                if(selectedButtonCount == 1){
//                    button->isPressed = !button->isPressed;
//                }else{
//                    selectedButtonCount--;
//                }
//            }
//            return;
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
        toReturn[i].percent = QString::number(buttons[i]->intensity);
    }

    return toReturn;
}
