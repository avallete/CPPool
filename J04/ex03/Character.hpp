#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character: public ICharacter
{
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		std::string const & getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character& operator=(Character const & rhs);
	protected:
		int getIndex(void) const;
		AMateria** getMateria(void) const;
	private:
		int			_idx;
		AMateria*	_mat[4];
		std::string _name;
};
#endif