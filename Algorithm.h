#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <filehandler.h>
#include "contracts.h"

class Algorithm{
private:

public:
    Algorithm(ModelData* data)
        : data(data){
        content = "";
    }

    std::string content;
    ModelData* data;
    virtual std::string run(ModelData* data) = 0;
    virtual void cleanUp() =0;
            //body is always this->content = this->run(nullptr);

    virtual ~Algorithm(){
        FileHandler::getInstance().appendContent(this->content);
    }
};

#endif // ALGORITHM_H

