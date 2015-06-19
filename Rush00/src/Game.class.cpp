#include "Game.class.hpp"

Game::Game(void)
{
	return;
}

Game::Game(Game const & src)
{
	*this = src;
	return;
}

Game::~Game(void)
{
	return;
}

Game& Game::operator=(Game const & rhs)
{
	return (*this);
}