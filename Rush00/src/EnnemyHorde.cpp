#include "EnnemyHorde.hpp"

EnnemyHorde::EnnemyHorde(void): AObject()
{
	m_horde = NULL;
	m_number = 0;
	m_hp = 1;
	return;
}

EnnemyHorde::EnnemyHorde(int N)
{
	m_horde = new EnnemyHorde[N]();
	m_number = N;
	m_hp = 1;
	return;
}

EnnemyHorde::EnnemyHorde(int N, std::string form)
{
	m_horde = new EnnemyHorde[N]();
	m_number = N;
	for (int i = 0; i < N; i++)
		m_horde[i].setForm(form);
	return;
}

EnnemyHorde::EnnemyHorde(EnnemyHorde const & src): AObject(src)
{
	*this = src;
	return;
}

EnnemyHorde::~EnnemyHorde(void)
{
	if (m_horde)
	{
		delete [] m_horde;
		m_horde = NULL;
	}
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
	for (int a = 0; a < m_number; a++)
	{
		int		i = 0;
		i = rand() % 8;
		if (i == 4)
			i = 0;
		else if (i < 4 && i >= 2)
			i = -1;
		else if (i < 2)
			i = -2;
		else if (i >= 7)
			i = 1;
		else
			i = 2;

		m_horde[a].setPos(rand()%(win.getX() - m_sizex), rand() % (win.getY() / 4));
		m_horde[a].setDir(i, 1);
		m_horde[a].setHP(1);
		m_horde[a].setSpeed(0);
	}
}

void		 EnnemyHorde::respawn(void)
{
	for (int i = 0; i < m_number; i++)
		m_hp = 1;
}

void		EnnemyHorde::die(Window& win)
{
	int		i = 0;
	i = rand() % 8;
	if (i == 4)
		i = 0;
	else if (i < 4 && i >= 2)
		i = -1;
	else if (i < 2)
		i = -2;
	else if (i >= 7)
		i = 1;
	else
		i = 2;
	this->AObject::explode(win, 0);
	refresh();
	usleep(10);
	this->setPos(rand()%(win.getX() - m_sizex), 0);
	this->setDir(i, 1);
	this->setSpeed(0);
	this->setHP(1);
}

void		EnnemyHorde::printit(Window& win) const
{
	start_color();
	init_pair(8,COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(8));

	for (int i = 0; i < m_number; i++)
		m_horde[i].AObject::printit(win);
	attroff(COLOR_PAIR(8));
}

void		EnnemyHorde::move(Window& win)
{
	int		i = 0;
	i = rand() % 8;
	if (i == 4)
		i = 0;
	else if (i < 4)
		i = -1;
	else
		i = 1;
	this->setDir(i, 1);

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
