#ifndef GENERATOR_H
#define GENERATOR_H
#include "contracts.h"
#include <vector>
#include "contracts.h"
#include "time.h"
#include "stdlib.h"

using namespace std;

struct Config{
    int number = 100;
    bool gender;
    int seconds = 1200;
    vector<Muscle> relationship;
};

class Generator
{
public:
    Config config;
    Generator();
    ~Generator();
    ExerciseSecond* beginning(double,int,bool);
    vector<ModelData*> generateModels();

};

#endif // GENERATOR_H
