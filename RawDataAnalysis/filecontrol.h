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
    uint64_t   line;
    bool open(filesystem opening);
    bool save(filesystem saving);
    std::string read();
    bool write(std::string data);
    bool write(double data);
    std::string removeBefore(std::string str, char character);
    double strToDouble(std::string str);

    FILECONTROL();
};

#endif // FILE_H
