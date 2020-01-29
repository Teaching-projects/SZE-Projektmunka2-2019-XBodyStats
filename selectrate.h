#ifndef SELECTRATE_H
#define SELECTRATE_H
#include "Algorithm.h"
#include <string>

class SelectRate:public Algorithm
{
public:
    SelectRate(std::vector<ModelData*>& _data, AlgorithmParams* params);
    std::string run();
    ~SelectRate();
};

#endif // SELECTRATE_H
