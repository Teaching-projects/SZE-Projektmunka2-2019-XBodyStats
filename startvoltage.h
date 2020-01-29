#ifndef STARTVOLTAGE_H
#define STARTVOLTAGE_H
#include "Algorithm.h"
#include <cmath>
#include <string>

class StartVoltage: public Algorithm
{
public:
    StartVoltage(std::vector<ModelData*>& _data, AlgorithmParams* params);
    std::string run();
    ~StartVoltage();
};

#endif // STARTVOLTAGE_H
