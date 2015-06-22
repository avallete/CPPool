#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "EnnemyHorde.hpp"
#include "Player.hpp"

class Player: public AObject
{
	public:
		Player(Window& win);
		Player(Player const & src);
		~Player(void);
		void inputDirection(int);
		void checkEnemies(EnnemyHorde*, int, Window&);
		void move(Window& win);
		void printit(Window& win) const;
		void print_life(Window & win) const;


		Player& operator=(Player const & rhs);
		int input;
	private:
		Player(void);
		std::string _name;
};
#endif
