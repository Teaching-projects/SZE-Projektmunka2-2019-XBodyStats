#ifndef MODEL_H
#define MODEL_H
#include "contracts.h"

// Manages connection with database
class Model
{
private:
protected:
    ModelData* data;
public:
    Model(){}
    virtual ~Model(){delete data;}

    //TODO implement database
    virtual ModelData* getData() const = 0;
};

#endif // MODEL_H
