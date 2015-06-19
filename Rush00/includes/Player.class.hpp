#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

class Player
{
	public:
		Player(void);
		Player(Player const & src);
		~Player(void);

		Player& operator=(Player const & rhs);
	int	posx;
	int	posy;
	int	size;
};
#endif