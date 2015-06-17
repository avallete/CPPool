#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad: public ISquad
{
	public:
		Squad(void);
		Squad(Squad & src);
		~Squad(void);

		int				getCount() const;
		ISpaceMarine*	getUnit(int);
		int				push(ISpaceMarine*);
		Squad& operator=(Squad & rhs);
	private:
		ISpaceMarine**	_squad;
		int				_count;
};
#endif