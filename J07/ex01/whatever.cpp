#include <iostream>

template< typename P, typename Q, typename R >
void iter(P* ptr, Q len, R f(P))
{
	if (ptr != NULL)
	{
		for (Q i = 0; i < len; i++)
			f(ptr[i]);
	}
}

template<typename K>
void showthat(K that)
{
	std::cout << that << std::endl;
}

template<typename F>
int lenthat(F that)
{
	(void)that;
	return (5);
}

void print(std::string s)
{
	std::cout << "printstring : " << s << std::endl;
}

void ftchar(char c)
{
	std::cout << "char function: " << c << std::endl;
}

void inc(int i)
{
	i += 1;
	std::cout << "inc i: " << i << std::endl; 	
}

void dec(double i)
{
	i -= 1;
	std::cout << "dec i: " << i << std::endl;
}

int main(void)
{
	int array_int[5] = {42, 43, 44, 54, 56};
	char array_char[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	double array_double[3] = {12, 34e300, 2343234};
	std::string array_string[4] = {"toto", "titi", "tutu"};

	iter<int, int, void>(array_int, 5, &inc);
	iter<char, int, void>(array_char, 10, &ftchar);
	iter<double, int, void>(array_double, 3, &dec);
	iter<std::string, int, void>(array_string, 3, &print);
	iter<char, int, void>(array_char, 4 , showthat<char>);
	iter<char, int, void>(array_char, 4 , showthat<char>);
	iter<int, int, void>(array_int, lenthat<int*>(array_int), &inc);
}