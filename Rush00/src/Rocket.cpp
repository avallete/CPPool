/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlevieil <jlevieil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:01:41 by jlevieil          #+#    #+#             */
/*   Updated: 2015/06/21 19:07:05 by jlevieil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rocket.hpp"


Rocket::Rocket(int N, std::string form)
{
	m_max = N;
	m_index = 0;
	m_rockets = new Rocket[N];
	for (int i = 0; i < N; i++)
	{
		m_rockets[i].setForm(form);
		m_rockets[i].setDir(0, -1);
		m_rockets[i].setHP(0);
	}
}

Rocket::Rocket(void): AObject()
{
	return;
}


Rocket::Rocket(Rocket const & src): AObject(src)
{
	*this = src;
	return;
}

Rocket::~Rocket(void)
{
	if (m_rockets)
		delete [] m_rockets;
	return;
}

Rocket* Rocket::getRocket(void) const
{
	return (m_rockets);
}

int			 Rocket::getIndex(void) const
{
	return (m_index);
}

int			 Rocket::getMax(void) const
{
	return (m_max);
}

int			Rocket::check_m_dispo(void)
{
	int		i = 0;
	while (i < m_max)
	{
		if (m_rockets[i].getHP() == 0)
			return i;
		i++;
	}
	return -1;
}

void		Rocket::activate(int xpos, int ypos, int input)
{
	int		i = check_m_dispo();
	if (input == 10 && i >= 0)
	{
		m_rockets[i].setPos(xpos + 1, ypos - 1);
		m_rockets[i].setHP(1);
	}
}

void		Rocket::checkDamages(EnnemyHorde* horde, int Nu, Window& win)
{
	int center;
	int centerv;
	for (int i = 0; i < m_max; i++)
	{
		for (int e = 0; e < Nu; e++)
		{
			if (m_rockets[i].getHP() > 0 && horde[e].getHP() > 0)
			{
				if (abs(m_rockets[i].getY() - horde[e].getY()) <= 3)
				{
					center = horde[e].getX() + (horde[e].getsizeX() / 3);
					centerv = m_rockets[i].getX();
					centerv -= center;
					if (abs(centerv) <= 2)
					{
						m_rockets[i].explode(win, 1);
						horde[e].die(win);
					}
				}
			}
		}
	}
}

void		Rocket::printit(Window& win) const
{
	start_color();
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(7));

	for (int i = 0; i < m_max; i++)
		m_rockets[i].AObject::printit(win);
	attroff(COLOR_PAIR(7));
}

void		Rocket::move(Window& win)
{
	for (int i = 0; i < m_max; i++)
	{
		if (m_rockets[i].getY() < 0)
		{
			m_rockets[i].setHP(0);
		}
		m_rockets[i].AObject::move(win);
	}
}

Rocket& Rocket::operator=(Rocket const & rhs)
{
	AObject::operator=(rhs);
	return (*this);
}

void		Rocket::print_chargeur(Window & win)
{
	int i = 0;
	int mun = 0;
	while (i < m_max)
	{
		if (m_rockets[i].getHP() == 0)
			mun++;
		i++;
	}

	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));
	mvwprintw(win.getWin(), win.getY() - 19 + i , win.getX() - 46 , "   ___  ____  _______ __");
	mvwprintw(win.getWin(), win.getY() - 18 + i , win.getX() - 46 , "  / _ \\/ __ \\/ ___/ //_/  []");
	mvwprintw(win.getWin(), win.getY() - 17 + i , win.getX() - 46 , " / , _/ /_/ / /__/ ,<   ");
	mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 46 , "/_/|_|\\____/\\___/_/|_|    [] ");
	attroff(COLOR_PAIR(18));

	if (mun > m_max - (m_max / 3) || mun == m_max)
		attron(COLOR_PAIR(5));
	else if (mun > m_max - (2 * m_max / 3) || mun == m_max / 2)
		attron(COLOR_PAIR(7));
	else
		attron(COLOR_PAIR(6));
	for (i = 1; i < m_max + 1; i++)
		if ( i == m_max)
			mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 14 , "|____________");
		else
			mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 14 , "| ");
	for (i = 1; i < m_max + 1; i++)
		mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 2 , "| ");

	while ( mun > 0)
	{
		mvwprintw(win.getWin(), win.getY() - m_max - 13 -  (mun - m_max) , win.getX() - 12, "#########");
		mun--;
	}
	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
}



