template< typename T >
void	swap(T& l, T& r){
	T q(l); 
	l = r; 
	r = q;
}

template< typename U >
U const & min(U const & l, U const & r){
	return ((l < r) ? l : r);
}

template< typename F >
F const & max(F const & l, F const & r){
	return ((l > r) ? l : r);
}

#include <iostream>
int main(void)
{
	std::cout << "my test =============" << std::endl;
	int j = 1;
	int e = 2;
	float f = 3.4f;
	float g = 3.4f;
	double h = 2523543;
	double i = 3242341;
	std::cout << "max with int: " << max<int>(j, e) << std::endl;
	std::cout << "max with float: " << max<float>(f, g) << std::endl;
	std::cout << "max with double: " << max<double>(h, i) << std::endl;
	std::cout << "min with int: " << min<int>(j, e) << std::endl;
	std::cout << "min with float: " << min<float>(f, g) << std::endl;
	std::cout << "min with double: " << min<double>(h, i) << std::endl;
	std::cout << "swap with int: " << std::endl;  ::swap<int>(j, e);
	std::cout << "swap with float: " << std::endl;  ::swap<float>(f, g);
	std::cout << "swap with double: " << std::endl;  ::swap<double>(h, i);
	std::cout << " =============" << std::endl;
	int a = 2;

	int b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;

	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";

	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;

	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}