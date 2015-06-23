#include "Base.hpp"
#include <iostream>

Base* generate(void)
{
	int r = rand();
	if (!(r % 5))
		return (new A);
	else if (!(r % 2))
		return (new B);
	else
		return(new C);
}

void identify_from_pointer(Base* p)
{
	A* a;
	B* b;
	C* c;
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception)
			{
				std::cout << "No viable convertion" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *test;
	srand(time(NULL));
	test = generate();
	identify_from_pointer(test);
	identify_from_reference(*test);
	return (0);
}