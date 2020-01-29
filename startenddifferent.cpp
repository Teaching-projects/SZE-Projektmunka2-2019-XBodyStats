#include "startenddifferent.h"
#include <sstream>

StartEndDifferent::StartEndDifferent(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data,params){}

std::string StartEndDifferent::run(){
    double sum[11];

    for(int i =0;i<11;i++){
        sum[i] = 0;
    }

    double avrg[11];
    double currentPercents[11];
    int db = 0;

    for(auto d:data){
        double bmi = d->user.weight/pow(d->user.height/100.0, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            db++;
            for (int i = 0; i < 11; i++) {
                currentPercents[i] = d->seconds[0]->muscles[i]->percent;
            }
            for (auto s:d->seconds) {
                for(int i = 0; i<11; i++){
                    if(s->muscles[i]->isSelected == true){
                        currentPercents[s->muscles[i]->muscle] = s->muscles[i]->percent;
                        int k;
                    }
                }
            }
            for(int i = 0; i < 11; i++){
                sum[i] += currentPercents[i];
            }
        }
    }
    std::string toreturn = "\n\n\n-----------------\nOutput of StartEndDifferent:\nEbben a kategoriaban az izomcsoportok atlagos zaro feszultsegszintje: \n";
    std::stringstream ss("");
    ss << "\n\n\n-----------------\nOutput of StartEndDifferent:\nEbben a kategoriaban az izomcsoportok atlagos zaro feszultsegszintje: \n";
    for(int i = 0; i < 11; i++){
        avrg[i] = sum[i]/ db;
        ss << this->format(izomcsoport[i], 4) << '\t' << std::setprecision(4) << avrg[i] << "%\n";
        //toreturn += this->format(izomcsoport[i],4) + '\t' + std::to_string(avrg[i]) + "%\n";
    }
    toreturn = ss.str();
    return toreturn;
}

StartEndDifferent::~StartEndDifferent(){
    FileHandler::getInstance().appendContent(this->run());
}
