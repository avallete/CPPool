#include "Loger.hpp"

int main(void)
{
    Loger test("testlog.txt");
    std::string mode[2] = {"file", "console"};
    std::string mess[4] = {"Okay a little log mess", "and an another", "Unicorn is the definition of dickhead", "Ohhh, i'm late !!!"};
    test.log(mode[0] , mess[0]);
    test.log(mode[0] , mess[1]);
    test.log(mode[0] , mess[2]);
    test.log(mode[0] , mess[3]);
    test.log(mode[1] , mess[0]);
    test.log(mode[1] , mess[1]);
    test.log(mode[1] , mess[2]);
    test.log(mode[1] , mess[3]);
    return 0;
}