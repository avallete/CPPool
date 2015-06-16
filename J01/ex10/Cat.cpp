#include "Cat.hpp"

Cat::Cat(void)
{
    return;
}

Cat::Cat(char* filename): _filename(filename)
{
    this->_file.open(filename, std::ifstream::in | std::ifstream::binary);
    return;
}

Cat::~Cat(void)
{
    if (this->_file.is_open())
        this->_file.close();
    return;
}
void        Cat::readToFile(std::string mess)
{
    if (this->_file.is_open())
    {

    }
    else
        std::cout << "cato9tails: " << this->_filename << ": Aucun fichier ou dossier de ce type";
}

void        Cat::readToStdo(void)
{
    std::string mess;
    while (std::getline(std::cin, mess))
        std::cout << mess << std::endl;
}