#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

class Cat
{
public:
                Cat(void);
                Cat(char* filename);
                ~Cat(void);
    void        readToFile(void);
    void        readToStdo(void);
    void		setFile(char *filename);
private:
    std::ifstream   _file;
    std::string     _filename;
};
#endif