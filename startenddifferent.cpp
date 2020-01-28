#include "startenddifferent.h"

StartEndDifferent::StartEndDifferent(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string StartEndDifferent::run(){
    int sum[11];
    int avrg[11];
    int currentPercents[11];

    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            /*for(auto m: d->seconds[d->seconds.size()]->muscles){

                if(m->muscle == muscle){
                    sum += m->percent;
                    db++;
                }
              }*/
            for (int i = 0; i < 1; i++) {
                currentPercents[i] = d->seconds[0]->muscles[i]->percent;
                sum[i] = 0;
            }
            for (auto s:d->seconds) {
                for(int i = 0; i<11; i++){
                    if(s->muscles[i]->isSelected = true){
                        currentPercents[i] = s->muscles[i]->percent;
                    }
                }
            }
            for(int i = 0; i < 11; i++){
                sum[i] += currentPercents[i];
            }
        }
    }
    std::string toreturn = "Ebben a kategoriaban az izomcsoportok atlagos feszultsegszintje: \n";
    for(int i = 0; i < 11; i++){
        avrg[i] = sum[i]/data.size();
        toreturn += std::to_string(i) + '\t' + std::to_string(avrg[i]) + '\n';
    }
    return toreturn;
}

StartEndDifferent::~StartEndDifferent(){
    FileHandler::getInstance().appendContent(this->run());
}
