#ifndef CONTRACTS_H
#define CONTRACTS_H
#include <qstring.h>
//TODO implement these

struct MuscleButtonProperties{
    bool isPressed;
    int buttonId;
    QString percent;
};

struct MasterButton{
    bool isVisible;
    bool isPressed;
    QString percent;
};

struct BurstTimeIndicator{
    QString time;
    int color;
};

// View will be displayed directly by View
struct ViewContent  {
   MuscleButtonProperties *buttons;
   bool selectButtonPressed;
   bool ASPButton;
   QString clock;
   BurstTimeIndicator timeIndicator;
   MasterButton masterButton;
   //int slideValue; only if needed
};

// Will be used in DataMining constructor acquired from Model
struct ModelData{

};


#endif // CONTRACTS_H
