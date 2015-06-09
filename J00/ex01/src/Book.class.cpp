#include "Book.class.hpp"

	Book::Book(void)
	{
		return;
	}

	Book::~Book(void)
	{
		return;
	}

	void Book::add(void)
	{
		if (Book::_index < 8)
		{
			this->_list[Book::_index].take_infos();
			Book::_index += 1;
		}
		else
			std::cout << "Sorry your BookPhone is full, for 300$ you can buy one another" << std::endl;
	}
	void Book::search(void)
	{
		int			i;
		std::string	nb;

		i = 0;
		while (i < Book::_index)
		{
			if (this->_list[i].valid_contact() == true)
			{
				std::cout << "| " << i << " |";
				this->_list[i].get_search();
				std::cout << std::endl;
			}
			i++;
		}
		std::cout << "Enter the desired contact number: ";
		getline(std::cin, nb);
		i = nb[0] -= 48;
		if (i >= 0 && i <= 7 && this->_list[i].valid_contact() == true)
			this->_list[i].get_infos();
		else
			std::cout << "Bad input, fuck off !" << std::endl;
	}
	int Book::_index = 0;