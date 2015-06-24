#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template<typename T>class Array
{
private:
	T* 				_arr;
	unsigned int	_len;

public:
	Array<T>(void): _arr(NULL), _len(0)
	{
		return;
	}

	Array<T>(Array<T> const & src): _arr(NULL), _len(0)
	{
		*this = src;
		return;
	};

	Array<T>(unsigned int n): _arr(new T[n]()), _len(n)
	{
		return;
	};

	~Array<T>(void)
	{
		if (_arr)
		{
			delete [] _arr;
			_arr = NULL;
		}
	};

	unsigned int size(void) const
	{
		return (_len);
	};

	Array<T>&	operator=(Array<T> const & rhs)
	{
		if (this == &rhs)
			return *this;
		if (_arr)
			delete [] _arr;
		_len = rhs.size();
		_arr = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			_arr[i] = rhs[i];
		return (*this);
	};

	T&		operator[](unsigned int index) const
	{
		if (index > _len || index < 0)
			throw std::out_of_range("Index out of range.");
		else
			return (_arr[index]);
	};
};
#endif