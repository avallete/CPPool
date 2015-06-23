#include <iostream>
#include <iomanip>

struct Data{std::string s1; int n; std::string s2;};

void	*serialize(void)
{
	char pool[10] = "abcdefghi";
	char *r = new char[19];
	int a = rand();
	char tmp[8] = {0};
	char tmp2[8] = {0};
	for (int i = 0; i < 7; i++)
	{
		tmp[i] = pool[rand() % 8];
		tmp2[i] = pool[rand() % 8];
	}
	void *ret;
	for (int i = 0; i <= 19; i++)
	{
		if (i < 8)
		 	r[i] = tmp[i];
		else if (i >= 12)
		 	r[i] = tmp2[i - 12];
		else
		 r[i] = (reinterpret_cast<char*>(&a)[i - 8]);
	}
	ret = reinterpret_cast<void *>(r);
	return (ret);
}

Data*	deserialiaze(void *raw)
{
	Data *ret = new Data;
	ret->s1 = reinterpret_cast<char *>(reinterpret_cast<int *>(raw));
	ret->n = *reinterpret_cast<int *>(static_cast<char*>(raw) + 8);
	ret->s2 = reinterpret_cast<char *>(reinterpret_cast<int *>(static_cast<char*>(raw) + 12));
	return (ret);
}

int 	main(void)
{
	srand(time(NULL));
	void *ser;
	Data* data;

	ser = serialize();
	data = deserialiaze(ser);
	std::cout << data->s1 << std::endl <<
	data->n << std::endl <<
	data->s2 << std::endl;
	return (0);
}