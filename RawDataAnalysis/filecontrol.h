#ifndef FILECONTROL_H
#define FILECONTROL_H

#include <string>
#include <fstream>


struct filesystem{
    std::string Path;
    std::string FileName;
};

class FILECONTROL{
private:
    std::ifstream importFile;
    std::ofstream saveFile;
public:
    filesystem opening;
    filesystem saving;
    bool open(filesystem opening);
    bool save(filesystem saving);
    std::string read();
    bool write(std::string data);

    FILECONTROL();
};

#endif // FILE_H
