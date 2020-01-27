#ifndef GENERATOR_H
#define GENERATOR_H
#include "contracts.h"
#include <vector>
#include "contracts.h"
#include "time.h"
#include "stdlib.h"

using namespace std;

struct Config{
    int number;
    bool gender;
    int seconds = 1200;
    vector<Event> relationship;
};

class Generator
{
public:
    Config config;
    Generator();
    ~Generator();

    vector<ModelData*> generateModels();

};

#endif // GENERATOR_H
