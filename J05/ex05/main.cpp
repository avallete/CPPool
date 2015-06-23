#include <iostream>
#include "CentralBureaucracy.hpp"

int		main(void)
{
	std::string target[8] = {"coco", "cucu", "fifi", "Zaz", "Olive", "Pastis", "Arnaud"};
	CentralBureaucracy Central;
	Central.feedAllBureaucrat();
	Central.feedBureaucrat();
	for (int i = 0; i < 20; i++)
		Central.queueUp(target[rand() % 7]);
	Central.doBureaucracy();
}
