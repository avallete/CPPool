#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/mount.h>
#include <sys/resource.h>
#include <sstream>
#include <fstream>

std::string getCPUInfos(void)
{
	FILE *top;
	std::string extract;
	std::stringstream topinfos;
	char buf[512] = {0};
	float CPUsage[3] = {0};
	int Process[5] = {0};
	float LoadAvg[3] = {0};
	int SharedLibs[3] = {0};
	// int		Disks[4] = {0};

	top = popen("top -n 0 -l 1 -s 0 | sed '2d' | grep -o ' \\d*\\.\\d*\\| \\d*' | tr -d '[:blank:]' | sed '/^$/d'", "r");
	if (top)
	{
		while (fgets(buf, sizeof(buf), top) != NULL)
			topinfos << buf;
		for (int i = 0; i < 5; ++i)
			topinfos >> Process[i];
		for (int i = 0; i < 3; i++)
			topinfos >> LoadAvg[i];
		for (int i = 0; i < 3; i++)
			topinfos >> CPUsage[i];
		pclose(top);
	}
	return (extract);
}

// std::string getRamInfos(void)
// {
// 	std::stringstream ss;
// 	long HWram[10] = {0};
// 	size_t len = sizeof(int);

// 	return (ss.str());
// }

int main(void)
{
	std::string buf;

	do
	{
		std::cout << "CPU Infos: " << std::endl << getCPUInfos() << std::endl;
	}while (getline(std::cin, buf));
	return 0;
}