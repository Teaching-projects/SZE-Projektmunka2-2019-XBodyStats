#ifndef MASTERRATE_H
#define MASTERRATE_H
#include "Algorithm.h"
#include "cmath"
#include <string>

class MasterRate: public Algorithm
{ //van e olyan idopillanat ahol surubben hasznaljuk a mastert
public:
    MasterRate(std::vector<ModelData*>& _data, AlgorithmParams* params);
    std::string run();
    ~MasterRate();
private:
    int mins[3][20];

};

#endif // MASTERRATE_H
