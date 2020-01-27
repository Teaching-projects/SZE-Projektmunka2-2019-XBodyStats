#ifndef STARTVOLTAGE_H
#define STARTVOLTAGE_H
#include "Algorithm.h"
#include <string>

class StartVoltage: public Algorithm
{
public:
    StartVoltage(std::vector<ModelData*>& _data);
    std::string run();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;

    ~StartVoltage();
};

#endif // STARTVOLTAGE_H
