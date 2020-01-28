#include "masterallrate.h"

MasterAllRate::MasterAllRate(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string MasterAllRate::run(){
    int masterdb = 0;
    int osszdb = 0;
    for (auto d: data) {
        osszdb += d->seconds.size();
        for(auto s: d->seconds){
            if(s->master != nullptr){
                masterdb++;
            }
        }
    }
    double asd = ((masterdb/asd)*100);
    return  "Az edzesek soran a valtoztatasok " + std::to_string(asd) + "%-a tortent master gombbal(" + std::to_string(masterdb) + " db)";
}

MasterAllRate::~MasterAllRate(){
    FileHandler::getInstance().appendContent(this->run());
}
