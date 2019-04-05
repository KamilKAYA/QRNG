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
    mkdir(createPath.c_str(),0755);

    //std::string ofile="//"+this->writingFileName+"//"+this->writingFileName+".bin";

    std::string ofile;
    if(this->Base==2)ofile=createPath+"/"+this->writingFileName+".dat";

    if(this->Base==10)ofile=createPath+"/"+this->writingFileName+".dec";

    if(this->Base==16)ofile=createPath+"/"+this->writingFileName+".dat";

    this->importFile.open(readingFileName,std::ifstream::binary);
    if(importFile.fail()){
        this->complate=true;
        std::cout<<"No such file :"<<this->readingFileName<<std::endl;
    }

    this->exportFile.open(ofile.c_str(),std::ios::app | std::ios::binary);
    //this->exportFile<<"Random number bin file created by kamil.kaya@Ozyegin";
    this->line=0;
    //this->exportFile.close();
}


uint8_t QRNG::StartAnalysis(){
    this->sizeOfBitOne=0;
    this->sizeOfBitZero=0;
    this->line=0;
    size_t bitCount=0;
    static unsigned long long int readingLine=0;
    std::bitset<8> data;
    uint8_t data_dec[2]={0};
    float absCoef=-1*this->Threshold;
    while(!complate){

            this->importFile>>this->timeData>>this->voltage;
            if(this->importFile.fail())this->complate=true;

            if((readingLine%(this->Step))==0){
                if((this->voltage>=this->Threshold) /* ||  (this->voltage<=absCoef) */ ){
                    data[bitCount]=1;
                    this->sizeOfBitOne++;
                    data_dec[0] |=1UL<<bitCount;
                 }else {
                    data[bitCount]=0;
                    this->sizeOfBitZero++;
                 }
                bitCount++;
            }

            if(bitCount==this->BitLength){
                if(this->SizeOfData<this->line)this->complate=true;
                if(this->Base==2){
                    //std::cout<<data<<std::endl;
                    this->exportFile<<data<<"\t";
                }
                if(this->Base==10){
                    //std::cout<<(int)data_dec[0]<<std::endl;
                    this->exportFile<<(int)data_dec[0]<<"\n";
                }
                if(this->Base==16){
                    //std::cout<<(int)data_dec[0]<<std::endl;
                    this->exportFile.write((char*)data_dec,1);
                    //this->exportFile<<data_dec<<"\t";
                }
                memset(data_dec,0,4);
                bitCount=0;
                this->line++;
            }
            readingLine++;
            if((readingLine%100000)==0)std::cout<<".";
    }
return 255;
}


void QRNG::close(){
    exportFile.close();
}

QRNG::QRNG(){
    std::cout<<" QRNG Version:2.10"<<std::endl;
    std::cout<<" Welcome to QRNG data analysis program.\n\n Coded by Kamil KAYA \n Ozyegin University \n Department of Electric Electronic Engineering. \n\n "<<std::endl;
}
QRNG::~QRNG(){
    unsigned long long int totalData= this->sizeOfBitOne+this->sizeOfBitZero;
    double perOfOne= (this->sizeOfBitOne/(double)totalData)*100.0;
    double perOfZero= (this->sizeOfBitZero/(double)totalData)*100.0;

    std::cout<<" Processing finish. \n Some analysis about data are : \n Total bit # : "<<totalData<<"\n Total # of 1 : "<<this->sizeOfBitOne<<"\n Total # of 0 : "<<this->sizeOfBitZero<<std::endl;
    std::cout<<" Percentage of One : "<<perOfOne<<" %"<<"\n Percentage of Zero : "<<perOfZero<<" %"<<std::endl;
}

