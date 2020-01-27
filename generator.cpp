#include "generator.h"
#include <cmath>

using namespace std;

Generator::Generator()
{
    srand(time(nullptr));
}

int randomNumber(int chance, int lowThreshold = 0){
    int r;

    for(;;){
        r = (rand() % chance) + 1;
        if (r > lowThreshold){
            return r;
        }
    }
}

ExerciseSecond* beginning(double bmi, int age, bool sex){
    ExerciseSecond* toReturn;
    double lowerBMI = (bmi > 23) ? (bmi - (bmi - 23)*2) : bmi;

    double bmiPercent = abs(23/lowerBMI);
    double agePercent;

    if(age <= 30){
        agePercent = 1;
    }else if(age > 30){
        agePercent = 0.95;
    }else {
        agePercent = 0.9;
    }

    double sexPercent = 0.95;

    int max = 100 * bmiPercent * agePercent * sexPercent;

    int muscleStart[Calves];

    for(int i = Quadriceps; i <= Calves; i++){
        Muscle m = static_cast<Muscle>(i);

        int muscleMax = max - randomNumber(7);

        muscleStart[m] = muscleMax;
    }

    toReturn->time = 0;
    toReturn->master.percent = 50;
    //toReturn->muscles->muscle

    return toReturn;
}

vector<ModelData*> Generator::generateModels()
{
    vector<ModelData*> toReturn;


    for(int i=0; i<config.number; i++){
        ModelData* data = new ModelData();
        data->user.sex = randomNumber(2);
        data->user.age = randomNumber(60,18);
        data->user.height = randomNumber(190,155);
        data->user.weight = randomNumber(90,55);
        data->type = Weights;
        data->fileName = i;

        double bmi = data->user.weight / pow(2,(data->user.height/100));

        for(int j = 0;j<config.seconds;j++){

        }

        toReturn.push_back(data);

    }
    return toReturn;
}
