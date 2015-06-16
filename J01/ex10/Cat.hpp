#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include <fstream>
#include <string>

class Cat
{
public:
                Cat(void);
                Cat(char* filename);
                ~Cat(void);
    void        readToFile(void);
    void        readToStdo(void);
private:
    std::ifstream   _file;
    std::string     _filename;
};
#endif