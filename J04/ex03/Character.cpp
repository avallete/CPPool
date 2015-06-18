#include "Character.hpp"

Character::Character(void): _idx(0), _name("Clone Character")
{
	_mat[0] = NULL;
	_mat[1] = NULL;
	_mat[2] = NULL;
	_mat[3] = NULL;
	return;
}

Character::Character(std::string const & name): _idx(0), _name(name)
{
	_mat[0] = NULL;
	_mat[1] = NULL;
	_mat[2] = NULL;
	_mat[3] = NULL;
	return;
}

Character::Character(Character const & src)
{
	*this = src;
	return;
}

Character::~Character(void)
{
	return;
}

std::string const & Character::getName(void) const
{
	return((std::string&)_name);
}

int	 Character::getIndex(void) const
{
	return (_idx);
}

AMateria** Character::getMateria(void) const
{
	return ((AMateria**)_mat);
}

void Character::equip(AMateria* m)
{
	if (_idx <= 3 && _idx >= 0)
	{
		_mat[_idx] = m;
		_idx++;
	}
}
void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _mat[idx])
	{
		_mat[idx] = NULL;
		_idx--;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _mat[idx])
		_mat[idx]->use(target);
}

Character& Character::operator=(Character const & rhs)
{
	_name = rhs.getName();
	_idx = rhs.getIndex();
	_mat = rhs.getMateria();
	return (*this);
}