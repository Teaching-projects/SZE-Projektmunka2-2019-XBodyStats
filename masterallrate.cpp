#include "masterallrate.h"
#include <sstream>

MasterAllRate::MasterAllRate(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data,params){}

std::string MasterAllRate::run(){
    int masterdb = 0.0;
    double osszdb = 0.0;
    for (auto d: data) {
        osszdb += d->seconds.size();
        for(auto s: d->seconds){
            if(s->master != nullptr){
                masterdb++;
            }
        }
    }
    double asd = ((masterdb/osszdb)*100.0);
    //std::string sa =   "Az edzesek soran a valtoztatasok " + std::to_string(asd) + "%-a tortent master gombbal(" + std::to_string(masterdb) + " db)";
    std::stringstream ss("");
    ss << "\n\n\n-----------------\nOutput of MasterAllRate:\n";
    ss << "Az edzesek soran a valtoztatasok " << std::setprecision(4) << asd << "%-a tortent master gombbal(" << std::to_string(masterdb) << " db)";
    //std::cout << ss.str();
    std::string soi = ss.str();
    return soi;
}

MasterAllRate::~MasterAllRate(){
    FileHandler::getInstance().appendContent(this->run());
}
