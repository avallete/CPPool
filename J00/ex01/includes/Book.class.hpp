#ifndef BOOK_CLASS_HPP
#define BOOK_CLASS_HPP
#include "Contact.class.hpp"
class Book
{
	public:
					Book();
					~Book();
		void		search(void);
		void 		add(void);
	private:
		Contact		_list[8];
		static int	_index;
};
#endif