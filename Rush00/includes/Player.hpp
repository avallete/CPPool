#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "AObject.hpp"
#include "Player.hpp"

class Player: public AObject
{
	public:
		Player(Window& win);
		Player(Player const & src);
		~Player(void);
		void inputDirection(int);
		void move(Window& win);

		Player& operator=(Player const & rhs);
	private:
		Player(void);
		std::string _name;
};
#endif