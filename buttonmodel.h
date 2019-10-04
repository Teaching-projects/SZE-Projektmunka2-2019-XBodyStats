#ifndef BUTTONMODEL_H
#define BUTTONMODEL_H

#define PLUS true
#define MINUS false

#include "contracts.h"
#include <vector>

struct ButtonModel{
    int id;
    int intensity;
    bool isPressed;
};

class ButtonStore{
private:

public:
    std::vector<ButtonModel*> buttons;

    ButtonStore();
    ~ButtonStore();

    void deselectAll();
    void updateIntensity(int id, bool direction);
    void updateIntensities(bool direction);
    void buttonSelected(int id, bool multiple);
    void setButtonValues(int value);

    MuscleButtonProperties* getMuscleButtonProperties();
};

#endif // BUTTONMODEL_H
