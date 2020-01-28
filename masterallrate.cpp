#include "masterallrate.h"

MasterAllRate::MasterAllRate(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string MasterAllRate::run(){
    int masterdb;
    int osszdb = 0;
    for (auto d: data) {
        osszdb += d->seconds.size();
        for(auto s: d->seconds){
            if(s->master != nullptr){
                masterdb++;
            }
        }
    }

    return "Az edzesek soran a valtoztatasok " + std::to_string(masterdb/osszdb) + "%-a tortent master gombbal(" + std::to_string(masterdb) + " db)";
}

MasterAllRate::~MasterAllRate(){
    FileHandler::getInstance().appendContent(this->run());
}
