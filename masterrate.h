#ifndef MASTERRATE_H
#define MASTERRATE_H
#include "Algorithm.h"
#include <string>

class MasterRate: public Algorithm
{
public:
    MasterRate(std::vector<ModelData*>& _data);
    std::string run();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;
    int mins[2][20];

    ~MasterRate();
};

#endif // MASTERRATE_H
