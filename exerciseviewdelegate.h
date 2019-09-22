#ifndef EXERCISEVIEWDELEGATE_H
#define EXERCISEVIEWDELEGATE_H

//Delegate class inherited by ExerciseViewController
class ExerciseViewDelegate
{
public:
    ExerciseViewDelegate();
    virtual ~ExerciseViewDelegate();

protected:

    virtual void muscleButtonOnPress(int buttonId) =  0;
    virtual void mainButtinOnPress(bool direction) = 0;
    virtual void sliderChanged(int value) = 0;

    /* Will be added if needed
    virtual void optionsPressed();
    */
};

#endif // EXERCISEVIEWDELEGATE_H
