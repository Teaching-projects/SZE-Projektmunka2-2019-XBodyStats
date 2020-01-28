#ifndef STARTVOLTAGE_H
#define STARTVOLTAGE_H
#include "Algorithm.h"
#include <string>

class StartVoltage: public Algorithm
{
public:
    StartVoltage(std::vector<ModelData*>& _data);
    std::string run();
    ~StartVoltage();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;

};

#endif // STARTVOLTAGE_H
