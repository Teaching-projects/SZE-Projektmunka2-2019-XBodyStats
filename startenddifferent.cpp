#include "startenddifferent.h"

StartEndDifferent::StartEndDifferent(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string StartEndDifferent::run(){
    int sum = 0;
    int db = 0;
    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(auto m: d->seconds[d->seconds.size()]->muscles){
                if(m->muscle == muscle){
                    sum += m->percent;
                    db++;
                }
            }
        }
    }
    return "Ebben a kategoriaban a(z) " + std::to_string(this->muscle) + " atlagos zaro feszultsegszintje " + std::to_string(sum/db) + "%";
}

StartEndDifferent::~StartEndDifferent(){
    FileHandler::getInstance().appendContent(this->run());
}
