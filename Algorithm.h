#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <filehandler.h>
#include <iomanip>
#include "contracts.h"
#include<vector>

class Algorithm{
private:

public:
    Algorithm(std::vector<ModelData*>& _data):data(_data)
    {

        content = "";
    }

    int minage = 30;
    int maxage = 55;
    bool sex = 0;
    int minbmi = 18;
    int maxbmi = 25;

    std::string content;
    std::vector<ModelData*> data;
    virtual std::string run() = 0;
    //virtual void cleanUp() =0;
            //body is always this->content = this->run();

    virtual ~Algorithm(){
    }
};

#endif // ALGORITHM_H

