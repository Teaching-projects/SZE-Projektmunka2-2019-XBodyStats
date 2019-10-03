#ifndef CONTRACTS_H
#define CONTRACTS_H

//TODO implement these

// View will be displayed directly by View
struct ViewContent  {
   MuscleButtonProperties *buttons;
   bool selectButtonPressed;
   bool ASPButton;
   //int slideValue; only if needed
   MuscleButtonProperties *labels;
   QString clock;
   BurstTimeIndicator timeIndicator;
   MasterButton masterButton;
};

struct MuscleButtonProperties{
    bool isPressed;
    int buttonId;
};
struct MuscleLabelContent{
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

// Will be used in DataMining constructor acquired from Model
struct ModelData{

};


#endif // CONTRACTS_H
