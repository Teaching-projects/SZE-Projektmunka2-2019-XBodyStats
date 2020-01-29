#include "generator.h"
#include <cmath>
#include <iostream>

using namespace std;

Generator::Generator()
{
    this->config = Config();
    config.gender = 0;
    config.number = 100;
    config.seconds = 1200;
    config.relationship = vector<Muscle>();
    srand(time(nullptr));
}

int randomNumber(int chance, int lowThreshold = -999, int offset = 0){
    int r;

    for(;;){
        r = (rand() % chance) + 1 + offset;
        if (r > lowThreshold){
            return r;
        }
    }
}

ExerciseSecond* Generator::beginning(double bmi, int age, bool sex){
    ExerciseSecond* toReturn = new ExerciseSecond;
    double lowerBMI = (bmi > 23) ? (bmi - (bmi - 23)*2) : bmi;

    double bmiPercent = abs(lowerBMI / 23);
    double agePercent;

    if(age <= 30){
        agePercent = 1;
    }else if(age > 30){
        agePercent = 0.95;
    }else {
        agePercent = 0.9;
    }

    double sexPercent = sex ? 0.95 : 1.0;

    double max = 100.0 * bmiPercent * agePercent * sexPercent;

    int muscleStart[Calves];

    for(int i = Quadriceps; i <= Calves; i++){
        Muscle m = static_cast<Muscle>(i);

        int muscleMax = (int)max - randomNumber(10);
        muscleStart[m] = muscleMax;
        MuscleModel* muscle = new MuscleModel;
        muscle->muscle = m;
        muscle->percent = muscleStart[m];
        muscle->chagedWith = nullptr;
        muscle->isSelected = false;
        toReturn->muscles.push_back(muscle);
    }

    toReturn->time = 0;
    toReturn->master = new MasterButtonModel;
    toReturn->master->percent = 50;

    return toReturn;
}

vector<ModelData*> Generator::generateModels()
{
    vector<ModelData*> toReturn;


    for(int i=0; i<config.number; i++){
        ModelData* data = new ModelData();
        data->user.sex = (randomNumber(100) <= 50) ? false : true;
        data->user.age = randomNumber(60,18);
        data->user.height = randomNumber(190,155);
        data->user.weight = randomNumber(90,55);
        data->type = Weights;
        data->fileName = i;

        double bmi = data->user.weight / ((double)(data->user.height/100.0) * (double)(data->user.height/100.0));

        data->seconds.push_back(this->beginning(bmi,data->user.age,data->user.sex));

        bool useButton = (randomNumber(100) <= 50) ? false : true;

        ExerciseSecond* lastSecond = data->seconds.back();

        int lastPercents[11];
        for(int p = 0; p < 11 ; p++){
            lastPercents[p] = data->seconds[0]->muscles[p]->percent;
        }

        int db = 0;

        //cout << "--------------------------------\n";
        //cout << "NEW WORKOUT\n";
        //cout << "--------------------------------\n";
        for(int j = 120; j < config.seconds; j += 30){

            if (j % 10) {
                ExerciseSecond* m = new ExerciseSecond;
                m->time = j;
                m->master = new MasterButtonModel;
                m->master->percent = 50 + randomNumber(10,-999,-5);
                auto filler = this->filler(Calves);
                MuscleModel* asd = new MuscleModel;
                asd->muscle = Calves;
                asd->percent = 0;
                asd->isSelected = false;
                asd->chagedWith = nullptr;
                filler.push_back(asd);
                m->muscles.insert(m->muscles.end(),filler.begin(),filler.end());
                data->seconds.push_back(m);
                db++;
            }

            useButton = (randomNumber(100) <= 20) ? false : true;

            ExerciseSecond* sec = new ExerciseSecond();
            sec->time = j;
            sec->master = nullptr;
            sec->muscles = vector<MuscleModel*>();
            MuscleModel* n = new MuscleModel();
            n->muscle = Hamstring;
            n->percent = lastPercents[Hamstring];
            lastPercents[Hamstring] = n->percent;
            n->percent += randomNumber(5,-999,-4);
            if (n->percent >= 100){
                n->percent -= 10;
            }
            if (n->percent <= (data->seconds[0]->muscles[Hamstring]->percent-20)){
                n->percent += 5;
            }
            n->chagedWith = useButton ? new Event(Button) : new Event(Slider);
            n->isSelected = true;
            vector<MuscleModel*> filler = this->filler(Hamstring);
            sec->muscles.insert(sec->muscles.end(),filler.begin(),filler.end());
            sec->muscles.push_back(n);

            data->seconds.push_back(sec);
            lastSecond = sec;

            if (j < 1100){
                j += 5;
                ExerciseSecond* anotherSec = new ExerciseSecond();
                anotherSec->time = j;
                anotherSec->master = nullptr;
                anotherSec->muscles = vector<MuscleModel*>();
                MuscleModel* m = new MuscleModel();
                m->muscle = Quadriceps;
                m->percent = lastPercents[Quadriceps];
                //cout << "before:\t" << m->percent << "\t";
                m->percent += randomNumber(5,-999,-4);
                //cout << "after:\t" << m->percent << "\n";
                lastPercents[Quadriceps] = m->percent;
                if (m->percent >= 100){
                    m->percent -= 10;
                }
                double threshold = data->seconds[0]->muscles[Quadriceps]->percent * 0.8;
                if (m->percent <= threshold){
                    m->percent += 5;
                }
                m->chagedWith = useButton ? new Event(Button) : new Event(Slider);
                m->isSelected = true;
                vector<MuscleModel*> filler = this->filler(Quadriceps);
                anotherSec->muscles.insert(anotherSec->muscles.end(),filler.begin(),filler.end());
                anotherSec->muscles.push_back(m);
                data->seconds.push_back(anotherSec);
            }
        }

        for(int i = 0;i<50;i++){
            ExerciseSecond* m = new ExerciseSecond;
            m->time = 433;
            m->master = nullptr;
            MuscleModel* as = new MuscleModel;
            vector<MuscleModel*> filler = this->filler(Quadriceps);
            m->muscles.insert(m->muscles.end(),filler.begin(),filler.end());
            as->muscle = Quadriceps;
            as->percent = lastSecond->muscles[10]->percent + randomNumber(10,-999,-5);
            as->chagedWith = useButton ? new Event(Button) : new Event(Slider);
            as->isSelected = true;
            m->muscles.push_back(as);
            data->seconds.push_back(m);
        }

        for(int i = 0;i<50;i++){
            ExerciseSecond* m = new ExerciseSecond;
            m->time = 900;
            m->master = new MasterButtonModel;
            m->master->percent = 75;
            MuscleModel* as = new MuscleModel;
            auto filler = this->filler(Quadriceps);
            m->muscles.insert(m->muscles.end(),filler.begin(),filler.end());
            as->muscle = Quadriceps;
            as->percent = 50;
            as->chagedWith = nullptr;
            as->isSelected = false;
            m->muscles.push_back(as);
            data->seconds.push_back(m);
        }


        toReturn.push_back(data);
    }
    //cout << "asiudas";
    return toReturn;
}

vector<MuscleModel*> Generator::filler(Muscle except){
    vector<MuscleModel*> toReturn;
    for(int i=0; i<=Calves; i++)
    {
        Muscle eCurrent = (Muscle) i;
        if(eCurrent == except) {continue;}
        MuscleModel* m = new MuscleModel;
        m->isSelected = false;
        m->percent = 0;
        m->chagedWith = nullptr;
        m->muscle = Calves;
        toReturn.push_back(m);
    }
    return toReturn;
}

MuscleModel* Generator::getMuscle(vector<MuscleModel*>& muscles, int muscle)
{
    for(auto& x: muscles){
        if(x->muscle == muscle){
            return x;
        }
    }
}
