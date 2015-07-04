#include "AObject.hpp"

AObject::AObject(void):	m_posx(0), m_posy(0), m_dirx(0), m_diry(0), m_speed(0),
m_sizex(0), m_form(""), m_hp(1)
{
	return;
}

AObject::AObject(int posx, int posy, int dirx, int diry, int speed, int hp, std::string form):
m_posx(posx), m_posy(posy), m_dirx(dirx), m_diry(diry), m_speed(speed),
m_form(form), m_hp(hp)
{
	m_sizex = m_form.size();
	return;
}

AObject::AObject(AObject const & src)
{
	*this = src;
	return;
}

AObject::~AObject(void)
{
	return;
}

void			AObject::setHP(int i)
{
	m_hp = i;
}

int 			AObject::getX(void) const
{
	return (m_posx);
}

int 			AObject::getY(void) const
{
	return (m_posy);
}

int 			AObject::getdirX(void) const
{
	return (m_dirx);
}

int 			AObject::getdirY(void) const
{
	return (m_diry);
}

int 			AObject::getSpeed(void) const
{
	return (m_speed);
}

int				AObject::getsizeX(void) const
{
	return (m_sizex);
}

int				AObject::getHP(void) const
{
	return (m_hp);
}

std::string&	AObject::getForm(void) const
{
	return ((std::string&)m_form);
}

void					AObject::setPos(int x, int y)
{
	m_posx = x;
	m_posy = y;
	return;
}

void					AObject::setDir(int x, int y)
{
	m_dirx = x;
	m_diry = y;
	return;
}

void					AObject::setSpeed(int s)
{
	m_speed = s;
	return;
}

void					AObject::setForm(std::string form)
{
	m_form = form;
	m_sizex = form.size();
	return;
}

void		AObject::print_score(Window & win) const
{
	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvwprintw(win.getWin(), 1, 2, "SCORE :" );
	std::string		str;
	mvwprintw(win.getWin(), 1, 10, str.c_str());
	attroff(COLOR_PAIR(19));
}


void					AObject::explode(Window& win, int F)
{
	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	init_pair(9,COLOR_RED,COLOR_RED);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	refresh();
	if (F == 1)
	{
	attron(COLOR_PAIR(19));
	mvwprintw(win.getWin(), m_posy + 1, m_posx + 10, "+ 10");
	attroff(COLOR_PAIR(19));
	setScore();

	}
	refresh();
	attron(COLOR_PAIR(9));
	mvwprintw(win.getWin(), m_posy - 1, m_posx, ".!,");
	mvwprintw(win.getWin(), m_posy, m_posx, "-*-");
	mvwprintw(win.getWin(), m_posy + 1, m_posx, "'|`");
	attroff(COLOR_PAIR(9));
	refresh();
	attron(COLOR_PAIR(7));
	mvwprintw(win.getWin(), m_posy - 1, m_posx - 1, "\\ | /");
	mvwprintw(win.getWin(), m_posy, m_posx - 1, "- * -");
	mvwprintw(win.getWin(), m_posy + 1, m_posx - 1, "'/ | \\");
	attroff(COLOR_PAIR(7));
	win.printBorder();
	attron(COLOR_PAIR(6));
	mvwprintw(win.getWin(), m_posy - 2, m_posx - 1, ". . .");
	mvwprintw(win.getWin(), m_posy - 1, m_posx, "\\|/");
	attron(COLOR_PAIR(7));
	mvwprintw(win.getWin(), m_posy, m_posx - 2, "`--+--'");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(6));
	mvwprintw(win.getWin(), m_posy + 1, m_posx, " /|\\ ");
	mvwprintw(win.getWin(), m_posy + 2, m_posx - 1, "' | '");
	attroff(COLOR_PAIR(6));
	refresh();
}

void					AObject::move(Window& win)
{
	if (m_hp > 0)
	{
		if (m_posy > win.getY() || m_posy < 0)
			this->setPos(rand() % win.getX(), 0);
		if (m_posx - m_sizex < 0 || m_posx + m_sizex > win.getX())
			this->setDir(-this->getdirX(), this->getdirY());
		m_posx += m_dirx;
		m_posy += m_diry;
	}
}

void				AObject::printit(Window& win) const
{
	if (m_posx >= 0 && m_posx <= win.getX() && m_posy > 0 && m_posy < win.getY() && m_hp > 0)
		mvwprintw(win.getWin(), m_posy, m_posx, m_form.data());
}

void				AObject::colision(AObject& obj)
{
	m_hp -= 1;
	obj.m_hp -= 1;
}

void	AObject::setScore(void)
{
	m_score += 10;
}

void	AObject::setScoreZero(void)
{
	m_score = 0;
}

int	AObject::getScore(void)
{
	return m_score;
}

AObject& AObject::operator=(AObject const & rhs)
{
	m_posx = rhs.getX();
	m_posy = rhs.getY();
	m_dirx = rhs.getdirX();
	m_diry = rhs.getdirY();
	m_speed = rhs.getSpeed();
	m_sizex = rhs.getsizeX();
	m_form = rhs.getForm();
	m_hp = rhs.getHP();
	return (*this);
}

int AObject::m_score = 0;
