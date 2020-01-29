#ifndef MASSTERALLRATE_H
#define MASSTERALLRATE_H
#include "Algorithm.h"
#include <string>

class MasterAllRate:public Algorithm
{
public:
    MasterAllRate(std::vector<ModelData*>& _data, AlgorithmParams* params);
    std::string run();
    ~MasterAllRate();
};

#endif // MASSTERALLRATE_H
