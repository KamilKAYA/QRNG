#include "filecontrol.h"


FILECONTROL::FILECONTROL()
{
    this->line=0;
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
    this->saveFile.open(saving.Path+saving.FileName,std::ios::app); // | std::ios::binary
    return true;
}

std::string FILECONTROL::read(){
    line++;
    std::string lineData;
    this->importFile>>lineData;
    return lineData;
}

bool FILECONTROL::write(std::string data){
    this->saveFile<<data<<"\n";
    return true;
}
bool FILECONTROL::write(double data){
    this->saveFile<<data<<"\n";
    return true;
}

std::string FILECONTROL::removeBefore(std::string str, char character){
    std::size_t found = str.find(character);
    if (found!=std::string::npos){
        str.erase(0,found+1);
    }
    return str;
}

double FILECONTROL::strToDouble(std::string str){
    double result=std::stod(str);
    return result;
}

