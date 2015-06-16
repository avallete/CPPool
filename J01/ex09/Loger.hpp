#ifndef LOGER_HPP
#define LOGER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Loger
{
public:
                Loger(std::string const & filename);
                ~Loger(void);
    void        logToFile(std::string mess);
    void        logToConsole(std::string mess);
    std::string makeLogEntry(std::string & mess) const;
    void        log(std::string & dest, std::string & mess);
private:
    std::ofstream _logfile;
};
#endif