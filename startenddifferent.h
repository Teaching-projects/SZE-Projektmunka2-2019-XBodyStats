#ifndef STARTENDDIFFERENT_H
#define STARTENDDIFFERENT_H
#include "Algorithm.h"
#include <cmath>
#include <string>

class StartEndDifferent:public Algorithm
{
public:
    StartEndDifferent(std::vector<ModelData*>& _data, AlgorithmParams* params);
    std::string run();
    ~StartEndDifferent();
   // Muscle muscle;

};

#endif // STARTENDDIFFERENT_H
