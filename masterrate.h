#ifndef MASTERRATE_H
#define MASTERRATE_H
#include "Algorithm.h"
#include <string>

class MasterRate: public Algorithm
{ //van e olyan idopillanat ahol surubben hasznaljuk a mastert
public:
    MasterRate(std::vector<ModelData*>& _data);
    std::string run();
    ~MasterRate();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;
    int mins[3][20];

};

#endif // MASTERRATE_H
