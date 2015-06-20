#ifndef ENNEMY_HORDE_HPP
#define ENNEMY_HORDE_HPP
#include "AObject.hpp"

class EnnemyHorde: public AObject
{
	public:
		EnnemyHorde(int N);
		EnnemyHorde(int N, std::string form);
		EnnemyHorde(EnnemyHorde const & src);
		~EnnemyHorde(void);
		EnnemyHorde*	getHorde(void) const;
		int			 	getNumber(void) const;
		void		 	printit(Window& win) const;
		void			randomPOP(Window& win);
		void			move(Window& win);
		void			respawn(void);
		EnnemyHorde*	getHorde(void);
		int				getNumber(void);
		void			die(Window& win);

		EnnemyHorde& operator=(EnnemyHorde const & rhs);
	private:
		EnnemyHorde(void);
		EnnemyHorde*	m_horde;
		int				m_number;
};
#endif