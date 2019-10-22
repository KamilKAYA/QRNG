#include <iostream>
#include "filecontrol.h"
#include <string.h>
#include "postprocessing.h"

using namespace std;

static FILECONTROL readCSV;
static FILECONTROL saveDAT;


int main()
{
    string readingfile;
    string readingpath;

    string writingfile;
    string writingpath;

    cout<<" Ozyegin University, Department of EEE"<<endl;
    //cout<<" Please write file path where program will read : ";
    //cin>>readingpath;
    cout<<" Please write reading file name with path : ";
    cin>>readingfile;
    //cout<<" Please write file path where program will write : ";
    //cin>>writingpath;
    cout<<" Please write saving file name with path : ";
    cin>>writingfile;

    //readCSV.open({readingpath,readingfile});
    //saveDAT.save({writingpath,writingfile});
    readCSV.open({readingfile});
    saveDAT.save({writingfile});

    static uint64_t line=0;

    while(readCSV.lineIsAvailable()){
        string readline=readCSV.read();
        readline=readCSV.removeBefore(readline,',');
        double rawData=readCSV.strToDouble(readline);
        saveDAT.write(rawData);
        cout<<"Total reading line : "<<line<<" Data is : "<<rawData<<endl;
        line++;
    }
    return 0;
}
