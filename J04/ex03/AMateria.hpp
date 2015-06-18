#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);
		std::string const & getType(void) const;
		unsigned int getXP(void) const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria& operator=(AMateria const & rhs);
	private:
		AMateria(void);
		unsigned int _xp;
		std::string	_type;
};
#endif