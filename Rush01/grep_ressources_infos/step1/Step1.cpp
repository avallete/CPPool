#include <iostream>
#include <unistd.h>
#include <utility>
#include <sys/utsname.h>

std::string getHostName(void)
{
	char hostname[256] = {0};

	if (!gethostname(hostname, 255))
		return (std::string(hostname));
	else
		return (std::string("Unkown hostname"));
}

std::string getUserName(void)
{
	char username[256] = {0};

	if (!getlogin_r(username, 255))
		return (std::string(username));
	else
		return (std::string("Unkown username"));
}

std::string getOSInfos(void)
{
	struct utsname infos;
	std::string ret;

	if (!uname(&infos))
	{
		ret = "Sysname : ";
		ret += infos.sysname;
		ret += "\nNode Name: ";
		ret += infos.nodename;
		ret += "\nRelease: ";
		ret += infos.release;
		ret += "\nVersion: ";
		ret += infos.version;
		ret += "\nMachine: ";
		ret += infos.machine;
		return (ret);
	}
	else
		return (std::string("System Name Unkown"));
}

std::string getTime(void)
{
	time_t rawdate;
	struct tm *localdate;
	char buf[1024] = {0};

	time(&rawdate);
	localdate = localtime(&rawdate);
	strftime(buf, 1023, "%F %T", localdate);
	return (std::string(buf));
}

int main(void)
{
	std::string buf;

	do
	{
		std::cout << "Hostname: " <<  getHostName() << std::endl;
		std::cout << "Username: " <<  getUserName() << std::endl;
		std::cout << "Os info: " <<  getOSInfos() << std::endl;
		std::cout << "Date : " <<  getTime() << std::endl;
	}while (getline(std::cin, buf));
	return 0;
}