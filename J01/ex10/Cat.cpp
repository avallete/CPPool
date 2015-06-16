#include "Cat.hpp"

Cat::Cat(void)
{
    return;
}

Cat::~Cat(void)
{
    if (this->_file.is_open())
        this->_file.close();
    return;
}

void        Cat::readToFile(void)
{
    struct stat stats;
    std::string fcnt;
    if (this->_file.is_open())
    {
        stat(this->_filename.data(), &stats);
        if (stats.st_mode & S_IFDIR)
        {
            std::cout << "cato9tails: " << this->_filename << ": Is a directory" << std::endl;
            return;
        }
        else
        {
            while (getline(this->_file, fcnt))
                std::cout << fcnt << std::endl;
        }
    }
    else
        std::cout << "cato9tails: " << this->_filename << ": No such file or directory" << std::endl;
}

void        Cat::readToStdo(void)
{
    std::string mess;
    while (std::getline(std::cin, mess))
        std::cout << mess << std::endl;
}

void    Cat::setFile(char* filename)
{
    this->_filename = filename;
    this->_file.open(filename, std::ifstream::in | std::ifstream::binary);
    return;
}
