#include <iostream>
#include <string>
#include <fstream>

std::string get_file_content(std::ifstream& fd)
{
    std::string tmp;
    std::string file;

    file = "";
    while (getline(fd, tmp))
    {
        if (!tmp.empty())
        {
            file += tmp;
            file += "\n";
        }
    }
    return (file);
}

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream fs;
    std::ofstream out;
    std::string file;
    std::size_t pos;

    if (!filename.empty() && !s1.empty() && !s2.empty())
    {
        fs.open(filename.data());
        if (fs.is_open())
        {
            file = get_file_content(fs);
            while ((pos = file.find(s1)) != std::string::npos)
                file.replace(pos, s1.length(), s2);
            fs.close();
			filename += ".replace";
            out.open(filename.data());
            if (out.is_open())
            {
                out << file;
                out.close();
            }
            else
                std::cout << "Can't write in the file" << std::endl;
        }
        else
            std::cout << "Can't open file" << std::endl;
    }
    else
        std::cout << "Error" << std::endl;
}

int main(int argc, char const *argv[])
{
    if (argc == 4 && argv[1][0] && argv[2][0] && argv[3][0])
            replace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
    else
        std::cout << "Error: Usage=replace \"file\" \"s1\" \"s2\"" << std::endl;
    return 0;
}
