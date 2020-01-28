#ifndef VOLTAGERATE_H
#define VOLTAGERATE_H
#include "Algorithm.h"
#include <string>

class VoltageRate:public Algorithm
{
public:
    VoltageRate(std::vector<ModelData*>& _data);
    std::string run();
    ~VoltageRate();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;
    int mins[3][20];

};

#endif // VOLTAGERATE_H
