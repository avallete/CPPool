#ifndef SORCERER_HPP
#define SORCERER_HPP
#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer(void);
		std::string const & getName(void) const;
		std::string const & getTitle(void) const;

		Sorcerer&	operator=(Sorcerer const & rhs);
		void		polymorph(Victim const & vict) const;
	private:
		Sorcerer(void);
		std::string _name;
		std::string _title;
};
std::ostream&		operator<<(std::ostream& o, Sorcerer & rhs);
#endif