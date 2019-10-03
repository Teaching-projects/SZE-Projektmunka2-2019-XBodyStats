#ifndef BASEEXERCISEVIEW_H
#define BASEEXERCISEVIEW_H
#include "contracts.h"
#include "exerciseviewdelegate.h"

//AbstractClass implemented by ExerciseView
class BaseExerciseView
{
public:
    BaseExerciseView(){
        delegate->mainButtinOnPress();
        delegate->muscleButtonOnPress();
        delegate->sliderChanged(8);
    }

    virtual void display(ViewContent& viewContent);
    virtual ~BaseExerciseView();


private:
    ExerciseViewDelegate* delegate;
};

#endif // BASEEXERCISEVIEW_H
