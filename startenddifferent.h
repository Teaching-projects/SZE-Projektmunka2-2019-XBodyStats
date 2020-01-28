#ifndef STARTENDDIFFERENT_H
#define STARTENDDIFFERENT_H
#include "Algorithm.h"
#include <string>

class StartEndDifferent:public Algorithm
{
public:
    StartEndDifferent(std::vector<ModelData*>& _data);
    std::string run();
    ~StartEndDifferent();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;

};

#endif // STARTENDDIFFERENT_H
