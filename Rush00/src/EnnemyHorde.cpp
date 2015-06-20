#include "EnnemyHorde.hpp"

EnnemyHorde::EnnemyHorde(void): AObject()
{
	return;
}

EnnemyHorde::EnnemyHorde(int N)
{
	m_horde = new EnnemyHorde[N];
	m_number = N;
	m_hp = 1;
	return;
}

EnnemyHorde::EnnemyHorde(int N, std::string form)
{
	m_horde = new EnnemyHorde[N];
	m_number = N;
	for (int i = 0; i < N; i++)
		m_horde[i].setForm(form);
	return;
}

EnnemyHorde::EnnemyHorde(EnnemyHorde const & src)
{
	*this = src;
	return;
}

EnnemyHorde::~EnnemyHorde(void)
{
	delete [] m_horde;
	return;
}

EnnemyHorde* EnnemyHorde::getHorde(void) const
{
	return (m_horde);
}

int			 EnnemyHorde::getNumber(void) const
{
	return (m_number);
}

void		 EnnemyHorde::randomPOP(Window& win)
{
	for (int i = 0; i < m_number; i++)
	{
		m_horde[i].setPos(rand()%(win.getX() - m_sizex), rand() % (win.getY() / 4));
		m_horde[i].setDir(i % 2, 1);
		m_horde[i].setSpeed(0);
	}
}

void		 EnnemyHorde::respawn(void)
{
	for (int i = 0; i < m_number; i++)
		m_hp = 1;
}

void		EnnemyHorde::die(Window& win)
{
	this->AObject::explode(win);
	refresh();
	usleep(10);
	this->setPos(rand()%(win.getX() - m_sizex), rand() % (win.getY() / 4));
	this->setDir(0, 1);
	this->setSpeed(0);
	m_hp = 1;
}

void		EnnemyHorde::printit(Window& win) const
{
	for (int i = 0; i < m_number; i++)
		m_horde[i].AObject::printit(win);
}

void		EnnemyHorde::move(Window& win)
{
	for (int i = 0; i < m_number; i++)	
		m_horde[i].AObject::move(win);
}

EnnemyHorde* EnnemyHorde::getHorde(void)
{
	return (m_horde);
}

int			EnnemyHorde::getNumber(void)
{
	return (m_number);
}

EnnemyHorde& EnnemyHorde::operator=(EnnemyHorde const & rhs)
{
	m_horde = rhs.getHorde();
	m_number = rhs.getNumber();
	return (*this);
}