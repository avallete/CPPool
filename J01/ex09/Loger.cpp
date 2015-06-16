#include "Loger.hpp"

typedef void(Loger::*PTR)(std::string);

Loger::Loger(std::string const & filename)
{
    this->_logfile.open(filename.data(), std::ofstream::out | std::ofstream::app);
    return;
}

Loger::~Loger(void)
{
    if (this->_logfile.is_open())
        this->_logfile.close();
    return;
}

void        Loger::logToFile(std::string mess)
{
    if (this->_logfile.is_open())
        this->_logfile << mess << std::endl;
    return;
}

void        Loger::logToConsole(std::string mess)
{
    std::cout << mess << std::endl;
    return;
}

std::string Loger::makeLogEntry(std::string & mess) const
{
    std::time_t tt = std::time(NULL);
    std::tm *time = std::localtime(&tt);
    char strtime[23] = {0};
    std::strftime(strtime, 22, "%F:%T | ", time);
    return (std::string(strtime + mess));
}

void        Loger::log(std::string & dest, std::string & mess)
{
    PTR array[2] = {&Loger::logToConsole, &Loger::logToFile};
    std::string str[2] = {"console", "file"};
    for (int i = 0; i < 2; i++)
    {
        if (!str[i].compare(dest))
        {
            (this->*array[i])((makeLogEntry(mess)));
            return;
        }
    }
    return;
}
