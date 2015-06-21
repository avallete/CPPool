#include "Player.hpp"
#include <iostream>
Player::Player(void): AObject()
{
	return;
}

Player::Player(Window& win): AObject((win.getX() / 2), (win.getY() - 5), 0, 0, 1, 3, "|/\\|")
{
	return;
}

Player::Player(Player const & src): AObject(src)
{
	*this = src;
	return;
}

Player::~Player(void)
{
	return;
}

void				Player::printit(Window& win) const
{
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(5));
	if (m_posx >= 0 && m_posx <= win.getX() && m_posy > 0 && m_posy < win.getY() && m_hp > 0)
		mvwprintw(win.getWin(), m_posy, m_posx, m_form.data());
	attroff(COLOR_PAIR(5));
}

void Player::inputDirection(int ch)
{
	this->input = 1;
	if (ch == 259 || ch == 258)
		ch == 258 ? m_diry += 1 : m_diry -= 1;
	else if (ch == 260 || ch == 261)
		ch == 261 ?  m_dirx += 2 : m_dirx -= 2;
	if (m_dirx < -2)
		m_dirx = -2;
	if (m_dirx > 2)
		m_dirx = 2;
	if (m_diry < -1)
		m_diry = -1;
	if (m_diry > 1)
		m_diry = 1;
}

void Player::move(Window& win)
{
	this->input = !this->input;
	m_posy += (m_diry * m_speed);
	m_posx += (m_dirx * m_speed);
	if (m_posy <= 0)
		m_posy = 1;
	if (m_posy >= win.getY() - 1)
		m_posy = win.getY() - 1;
	if (m_posx <= 0)
		m_posx = 1;
	if (m_posx >= win.getX() - 1)
		m_posx = win.getX() - 2;
	if (this->input)
	 	this->setDir(0, 0);
}

void		Player::print_life(Window & win) const
{
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));

	mvwprintw(win.getWin(), win.getY() - 16 , win.getX() - 40 , "   __   ____________  ");
	mvwprintw(win.getWin(), win.getY() - 15 , win.getX() - 40 , "  / /  /  _/ __/ __/  []");
	mvwprintw(win.getWin(), win.getY() - 14 , win.getX() - 40 , " / /___/ // _// _/  ");
	mvwprintw(win.getWin(), win.getY() - 13 , win.getX() - 40 , "/____/___/_/ /___/    []");
	attroff(COLOR_PAIR(18));
	if (m_hp == 3)
	{
		attron(COLOR_PAIR(5));
		mvwprintw(win.getWin(), win.getY() - 17 , win.getX() - 10 , " _____ ");
		mvwprintw(win.getWin(), win.getY() - 16 , win.getX() - 10 , "|___ / ");
		mvwprintw(win.getWin(), win.getY() - 15 , win.getX() - 10 , "  |_ \\ ");
		mvwprintw(win.getWin(), win.getY() - 14 , win.getX() - 10 , " ___) |");
		mvwprintw(win.getWin(), win.getY() - 13 , win.getX() - 10 , "|____/ ");
		attroff(COLOR_PAIR(5));
	}
	else if (m_hp == 2)
	{
		attron(COLOR_PAIR(7));
		mvwprintw(win.getWin(), win.getY() - 17 , win.getX() - 10 , " ____  ");
		mvwprintw(win.getWin(), win.getY() - 16 , win.getX() - 10 , "|___ \\ ");
		mvwprintw(win.getWin(), win.getY() - 15 , win.getX() - 10 , "  __) |");
		mvwprintw(win.getWin(), win.getY() - 14 , win.getX() - 10 , " / __/ ");
		mvwprintw(win.getWin(), win.getY() - 13 , win.getX() - 10 , "|_____|");
		attroff(COLOR_PAIR(7));
	}
	else
	{	attron(COLOR_PAIR(6));
		mvwprintw(win.getWin(), win.getY() - 17 , win.getX() - 10 , "  _ ");
		mvwprintw(win.getWin(), win.getY() - 16 , win.getX() - 10 , " / |");
		mvwprintw(win.getWin(), win.getY() - 15 , win.getX() - 10 , "/  |");
		mvwprintw(win.getWin(), win.getY() - 14 , win.getX() - 10 , " | |");
		mvwprintw(win.getWin(), win.getY() - 13 , win.getX() - 10 , " |_|");
		attroff(COLOR_PAIR(6));
		//refresh();
	}
}

void Player::checkEnemies(EnnemyHorde* horde, int N, Window& win)
{
	int center;
	int centerv;
	for (int i = 0; i < N; i++)
	{
		if (horde[i].getY() == m_posy)
		{
			center = horde[i].getX() - (horde[i].getsizeX() / 2);
			centerv = m_posx - (m_sizex / 2);
			centerv -= center;
			if (abs(centerv) <= m_sizex)
			{
				m_hp -= 1;
				horde[i].die(win);
			}
		}
	}
}

Player& Player::operator=(Player const & rhs)
{
	AObject::operator=(rhs);
	return (*this);
}
