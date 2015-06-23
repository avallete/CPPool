#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	public:
		Base(void);
		Base(Base const & src);
		virtual ~Base(void);

		Base& operator=(Base const & rhs);	
};

class A: public Base
{};
class B: public Base
{};
class C: public Base
{};
#endif