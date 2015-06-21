#include "Missile.hpp"


Missile::Missile(int N, std::string form)
{
	m_max = N;
	m_index = 0;
	m_missiles = new Missile[N];
	for (int i = 0; i < N; i++)
	{
		m_missiles[i].setForm(form);
		m_missiles[i].setDir(0, -1);
		m_missiles[i].setHP(0);
	}
}

Missile::Missile(void): AObject()
{
	return;
}


Missile::Missile(Missile const & src): AObject(src)
{
	*this = src;
	return;
}

Missile::~Missile(void)
{
	if (m_missiles)
		delete [] m_missiles;
	return;
}

Missile* Missile::getMissile(void) const
{
	return (m_missiles);
}

int			 Missile::getIndex(void) const
{
	return (m_index);
}

int			 Missile::getMax(void) const
{
	return (m_max);
}

int			Missile::check_m_dispo(void)
{
	int		i = 0;
	while (i < m_max)
	{
		if (m_missiles[i].getHP() == 0)
			return i;
		i++;
	}
	return -1;
}

void		Missile::activate(int xpos, int ypos, int input)
{
	int		i = check_m_dispo();
	if (input == 32 && i >= 0)
	{
		m_missiles[i].setPos(xpos + 1, ypos - 1);
		m_missiles[i].setHP(1);
	}
}

void		Missile::checkDamages(EnnemyHorde* horde, int Nu, Window& win)
{
	int center;
	int centerv;
	for (int i = 0; i < m_max; i++)
	{
		for (int e = 0; e < Nu; e++)
		{
			if (m_missiles[i].getHP() > 0 && horde[e].getHP() > 0)
			{
				if (abs(m_missiles[i].getY() - horde[e].getY()) <= 3)
				{
					center = horde[e].getX() + (horde[e].getsizeX() / 3);
					centerv = m_missiles[i].getX();
					centerv -= center;
					if (abs(centerv) <= 2)
					{
						m_missiles[i].colision(horde[e]);
						m_missiles[i].explode(win);
						horde[e].die(win);
						m_missiles[i].setHP(0);
					}
				}
			}
		}
	}
}

void		Missile::printit(Window& win) const
{
	start_color();
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(7));

	for (int i = 0; i < m_max; i++)
		m_missiles[i].AObject::printit(win);
	attroff(COLOR_PAIR(7));
}

void		Missile::move(Window& win)
{
	for (int i = 0; i < m_max; i++)
	{
		if (m_missiles[i].getY() < 0)
		{
			m_missiles[i].setHP(0);
		}
		m_missiles[i].AObject::move(win);
	}
}

Missile& Missile::operator=(Missile const & rhs)
{
	AObject::operator=(rhs);
	return (*this);
}

void		Missile::print_chargeur(Window & win)
{
	int i = 0;
	int mun = 0;
	while (i < m_max)
	{
		if (m_missiles[i].getHP() == 0)
			mun++;
		i++;
	}

	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));
	mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 46 , "   ___   __  _____  _______ ");
	mvwprintw(win.getWin(), win.getY() - 15 + i , win.getX() - 46 , "  / _ | /  |/  /  |/  / __ \\ []");
	mvwprintw(win.getWin(), win.getY() - 14 + i , win.getX() - 46 , " / __ |/ /|_/ / /|_/ / /_/ /");
	mvwprintw(win.getWin(), win.getY() - 13 + i , win.getX() - 46 , "/_/ |_/_/  /_/_/  /_/\\____/  []");
	attroff(COLOR_PAIR(18));

	if (mun > m_max - (m_max / 3))
		attron(COLOR_PAIR(5));
	else if (mun > m_max - (2 * m_max / 3))
		attron(COLOR_PAIR(7));
	else
		attron(COLOR_PAIR(6));
	for (i = 1; i < m_max + 1; i++)
		if ( i == m_max)
			mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 14 , "|____________");
		else
			mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 14 , "| ");
	for (i = 1; i < m_max + 1; i++)
		mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 2 , "| ");

	while ( mun > 0)
	{
		mvwprintw(win.getWin(), win.getY() - m_max - 1 -  (mun - m_max) , win.getX() - 12, "#########");
		mun--;
	}
	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
}



