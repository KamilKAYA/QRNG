/*
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

*/


#include "QRNG.h"

using namespace std;
QRNG myRandomNumbers;


int main(){


start:
    cout<<" Welcome to QRNG data analysis program.\n\n Coded by Kamil KAYA \n Ozyegin University \n Department of Electric Electronic Engineering. \n\n "<<endl;
    float Limit;
    string readFileName, writeFileName;

    cout<<" Please enter input file name :";
    while(readFileName=="")cin>>readFileName;

    cout<<" Please enter output file name :";
    while(writeFileName=="")cin>>writeFileName;

    cout<<" Please enter high logic limit (float) :";
    cin>>Limit;

    cout<<" Please enter base number (2,10,16) :";
    int BaseNumber;
    cin>>BaseNumber;

    cout<<" Please enter size of byte :";
    unsigned long long int SizeofData;
    cin>>SizeofData;

    cout<<" Please enter length of bit :";
    unsigned int SizeofBit;
    cin>>SizeofBit;

    cout<<" Please enter scanning step :";
    unsigned int Step;
    cin>>Step;


    /*
    cout<<" Please enter lower limit (float) :";
    cin>>downLimit;
    */

    cout<<" Are you sure the information is correct?(Y/N)";
    char answer = '\0';
    while(answer!='Y'	&&	answer!='N')cin>>answer;
    if(answer=='N')goto start;

    myRandomNumbers.Init(readFileName,writeFileName,Limit,BaseNumber,SizeofData,Step,SizeofBit);

    myRandomNumbers.StartAnalysis();

     myRandomNumbers.close();

    return 0;
}
