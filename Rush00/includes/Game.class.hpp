#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

class Game
{
	public:
		Game(void);
		Game(Game const & src);
		~Game(void);

		Game& operator=(Game const & rhs);
	
};
#endif