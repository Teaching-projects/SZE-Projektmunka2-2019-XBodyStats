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
    Model();
    ~Model();

    //TODO implement database
    virtual ModelData* getData() const;
};

#endif // MODEL_H
