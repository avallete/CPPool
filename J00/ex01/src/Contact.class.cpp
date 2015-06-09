#include "Contact.class.hpp"

Contact::Contact()
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::take_infos(void)
{
	std::cout << "Please Enter Contact First Name : ";
	std::getline(std::cin, this->_infos[0]);
	std::cout << "Please Enter Contact Last Name : ";
	std::getline(std::cin, this->_infos[1]);
	std::cout << "Please Enter Contact Nick Name : ";
	std::getline(std::cin, this->_infos[2]);
	std::cout << "Please Enter Contact Login : ";
	std::getline(std::cin, this->_infos[3]);
	std::cout << "Please Enter Contact Postal Adress : ";
	std::getline(std::cin, this->_infos[4]);
	std::cout << "Please Enter Contact E-mail : ";
	std::getline(std::cin, this->_infos[5]);
	std::cout << "Please Enter Contact Phone Number: ";
	std::getline(std::cin, this->_infos[6]);
	std::cout << "Please Enter Contact Birthday Date: ";
	std::getline(std::cin, this->_infos[8]);
	std::cout << "Please Enter Contact Favorite Meal: ";
	std::getline(std::cin, this->_infos[8]);
	std::cout << "Please Enter Contact Underwears Colors: ";
	std::getline(std::cin, this->_infos[9]);
	std::cout << "Please Enter Contact Darkest Secret: ";
	std::getline(std::cin, this->_infos[10]);
}

void Contact::get_infos(void) const
{
	std::cout << "---------------- Infos: ----------------" << std::endl;
	std::cout << "Contact First Name :- " << this->_infos[0] << std::endl;
	std::cout << "Contact Last Name :- " << this->_infos[1] << std::endl;
	std::cout << "Contact Nick name :- " << this->_infos[2] << std::endl;
	std::cout << "Contact Login :- " << this->_infos[3] << std::endl;
	std::cout << "Contact Postal adress :- " << this->_infos[4] << std::endl;
	std::cout << "Contact E-mail :- " << this->_infos[5] << std::endl;
	std::cout << "Contact Phone Number :- " << this->_infos[6] << std::endl;
	std::cout << "Contact Birthday Date :- " << this->_infos[7] << std::endl;
	std::cout << "Contact Favorite Meal :- " << this->_infos[8] << std::endl;
	std::cout << "Contact Underwears Colors :- " << this->_infos[9] << std::endl;
	std::cout << "Contact Darkest Secret :- " << this->_infos[10] << std::endl;
	return;
}

void Contact::get_search(void) const
{
	int i;

	i = 0;
	while (i < 3)
	{
		std::cout << std::setw(10);
		this->_infos[i].size() > 10 ? std::cout << this->_infos[i].substr(0, 9) + "." : std::cout << this->_infos[i];
		std::cout << "|";
		i++;
	}
}

bool Contact::valid_contact(void) const
{
	for (int i = 0; i < 3; i++)
	{
		if (!this->_infos[i].empty())
			return (true);
	}
	return (false);
}