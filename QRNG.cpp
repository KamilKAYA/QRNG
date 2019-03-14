#include "QRNG.h"
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <errno.h>



void QRNG::Init(std::string readingFile,std::string writingFile,float ThresholdValue, int Base, unsigned long long int SizeOfData, unsigned int Step, unsigned int BitLength ){
    this->Threshold=ThresholdValue;
    this->readingFileName=readingFile;
    this->writingFileName=writingFile;
    this->Base=Base;
    this->SizeOfData=SizeOfData;
    this->Step=Step;
    this->BitLength=BitLength;

    std::cout<<"\nWill read from : "<<readingFileName<<" and will write to : "<<this->writingFileName<<std::endl;

    std::string createPath=this->writingFileName;
    //mkdir(createPath.c_str(),0755);

    //std::string ofile="//"+this->writingFileName+"//"+this->writingFileName+".bin";

    std::string ofile;
    if(this->Base==2)ofile=this->writingFileName+".bin";

    if(this->Base==10)ofile=this->writingFileName+".dec";

    if(this->Base==16)ofile=this->writingFileName+".hex";

    this->importFile.open(readingFileName,std::ifstream::binary);
    if(importFile.fail()){
        this->complate=true;
        std::cout<<"No such file :"<<this->readingFileName<<std::endl;
    }

    this->exportFile.open(ofile.c_str(),std::ios::app | std::ios::binary);
    this->exportFile<<"Random number bin file created by kamil.kaya@Ozyegin";
    this->line=0;
    //this->exportFile.close();
}


uint8_t QRNG::StartAnalysis(){
    this->line=0;
    size_t bitCount=0;
    unsigned long long int readingLine=0;
    std::bitset<8> data;
    uint8_t data_dec=0;
    while(!complate){

            this->importFile>>this->voltage;
            if(this->importFile.fail())this->complate=true;

            if((readingLine%(this->Step))==0){
                if(this->voltage>=this->Threshold){
                    data[bitCount]=1;
                    data_dec |=1UL<<bitCount;
                 }else data[bitCount]=0;
                bitCount++;
            }

            if(bitCount==this->BitLength){
                if(this->SizeOfData<this->line)this->complate=true;
                if(this->Base==2){
                    std::cout<<data<<std::endl;
                    this->exportFile<<"\n"<<data;
                }
                if(this->Base==10){
                    std::cout<<(int)data_dec<<std::endl;
                    this->exportFile<<"\n"<<(int)data_dec;
                }
                data_dec=0;
                bitCount=0;
                this->line++;
            }
            readingLine++;
    }
return 255;
}

/*
uint8_t QRNG::make_8bit_bin(){
    while(!complate){
        std::bitset<8> data;
            for(int i=0; i<8; i++){
                    this->importFile>>this->voltage;
                    if(this->importFile.fail())this->complate=true;
                if(this->voltage>=this->Threshold)data[i]=1;
                this->line++;
                }

        std::cout<<data<<std::endl;
        this->exportFile<<"\n"<<data;
    }
    //if(this->voltage==NULL)this->complate=true;

    //string ofile=this->writingFileName+"\\"+this->writingFileName.c_str()+".bin";
    //this->exportFile.open(ofile.c_str(),ios::app | ios::binary);

    //this->exportFile.close();
return 255;
}
*/

void QRNG::close(){
    exportFile.close();
}
