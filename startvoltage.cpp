#include "startvoltage.h"

StartVoltage::StartVoltage(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string StartVoltage::run(){
    //int sum = 0;
    int db = 0;
    //for(;;){} muscle iterálás

    int sum[11];
    int avrg[11];
    for (int i = 0; i < 11; i++) {
        sum[i] = 0;
    }
    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(int i = 0; i < 11; i++){
                sum[i] += d->seconds[0]->muscles[i]->percent;
            }
        }
    }
    std::string toreturn = "Ebben a kategoriaban az izomcsoportok atlagos feszultsegszintje: \n";
    for (int i = 0; i < 11; i++) {
        avrg[i] = sum[i] / data.size();
        toreturn += std::to_string(i) + '\t' + std::to_string(avrg[i]) + '\n';
    }
    return toreturn;
}

StartVoltage::~StartVoltage(){
    FileHandler::getInstance().appendContent(this->run());
}
