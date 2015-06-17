#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy(void);
		std::string&	getType(void) const;
		int				getHP(void) const;
		virtual	void	takeDamage(int);

		Enemy& operator=(Enemy const & rhs);
	private:
		Enemy(void);
		int	_hp;
		std::string	_type;
};
#endif