#ifndef MISSILE_HPP
#define MISSILE_HPP
#include "AObject.hpp"
#include "Player.hpp"
#include "EnnemyHorde.hpp"
#include "Window.hpp"

class Missile: public AObject
{
	public:
		Missile(int N, std::string form);
		Missile(Missile const & src);
		~Missile(void);
		Missile* getMissile(void) const;	
		int	getIndex(void) const;		
		int	getMax(void) const;
		void printit(Window& win) const;
		void move(Window& win);
		void activate(int xpos, int ypos, int input);
		void checkDamages(EnnemyHorde* horde, int N, Window& win);
		void print_chargeur(Window & win);
		Missile& operator=(Missile const & rhs);
		int			check_m_dispo(void);

	private:
		Missile(void);
		Missile* m_missiles;
		int		 m_max;
		int		 m_index;
};
#endif
