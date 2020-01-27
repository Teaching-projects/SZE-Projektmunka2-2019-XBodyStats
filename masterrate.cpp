#include "masterrate.h"

MasterRate::MasterRate(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string MasterRate::run(){
    int sum = 0;
    int db = 0;
    bool talalt;
    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(auto min: d->seconds){
                talalt = false;
                for(auto m: min->muscles){
                    if(*(m->chagedWith) == Master && talalt == false){
                        talalt = true;
                    }
                }
                if (talalt == true){
                    mins[0][(int)(min->time / 60)]++;
                }
            }
        }
    }
    return "hello world";
}

MasterRate::~MasterRate(){
    FileHandler::getInstance().appendContent(this->run());
}
