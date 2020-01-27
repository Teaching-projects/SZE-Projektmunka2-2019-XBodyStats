#ifndef SLIDEORBUTTON_H
#define SLIDEORBUTTON_H
#include "Algorithm.h"
#include <string>

class SlideOrButton: public Algorithm
{
public:
    SlideOrButton(std::vector<ModelData*>& _data);
    std::string run();
    //void cleanUp();
    ~SlideOrButton();
};

#endif // SLIDEORBUTTON_H
