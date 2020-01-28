#ifndef VOLTAGERATE_H
#define VOLTAGERATE_H
#include "Algorithm.h"
#include <cmath>
#include <string>

class VoltageRate:public Algorithm
{
public:
    VoltageRate(std::vector<ModelData*>& _data);
    std::string run();
    ~VoltageRate();
private:
    Muscle muscle = Quadriceps;
    int mins[3][20];

};

#endif // VOLTAGERATE_H
