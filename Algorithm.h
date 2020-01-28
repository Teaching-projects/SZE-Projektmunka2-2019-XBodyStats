#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <filehandler.h>
#include "contracts.h"
#include<vector>

class Algorithm{
private:

public:
    Algorithm(std::vector<ModelData*>& _data):data(_data)
    {

        content = "";
    }

    std::string content;
    std::vector<ModelData*> data;
    virtual std::string run() = 0;
    //virtual void cleanUp() =0;
            //body is always this->content = this->run();

    virtual ~Algorithm(){
    }
};

#endif // ALGORITHM_H

