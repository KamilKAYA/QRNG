#include "filecontrol.h"


FILECONTROL::FILECONTROL()
{

}


bool FILECONTROL::open(filesystem opening){
    this->opening.Path=opening.Path;
    this->opening.FileName=opening.Path;
    this->importFile.open(opening.Path+opening.FileName,std::ifstream::binary);
    if(this->importFile.is_open())return true;
    else return false;
}


bool FILECONTROL::save(filesystem saving){
    this->saving.Path=saving.Path;
    this->saving.FileName=saving.FileName;
    this->saveFile.open(saving.FileName.c_str(),std::ios::app); // | std::ios::binary
    return true;
}

std::string FILECONTROL::read(){

    return "true";
}

bool FILECONTROL::write(std::string data){

    return false;
}

