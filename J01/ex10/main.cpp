#include "Cat.hpp"

int main(int ac, char **av)
{
    std::string input;
    Cat         *files;
    int         i;

    i = 0;
    if (ac >= 2)
    {
        av++;
        files = new Cat[ac - 1];
        while (*av)
        {
            files[i].setFile(*av);
            files[i].readToFile();
            i++;
            av++;
        }
        delete [] files;
    }
    else
    {
        while (getline(std::cin, input))
            std::cout << input << std::endl;
    }
    return 0;
}