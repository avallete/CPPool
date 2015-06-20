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

void					AObject::explode(Window& win)
{
	mvwprintw(win.getWin(), m_posy - 1, m_posx, ".!,");
	mvwprintw(win.getWin(), m_posy, m_posx, "-*-");
	mvwprintw(win.getWin(), m_posy + 1, m_posx, "'|`");
	refresh();
	usleep(100);
	mvwprintw(win.getWin(), m_posy - 1, m_posx - 1, "\\ | /");
	mvwprintw(win.getWin(), m_posy, m_posx - 1, "- * -");
	mvwprintw(win.getWin(), m_posy + 1, m_posx - 1, "'/ | \\");
	refresh();
	usleep(100);
	mvwprintw(win.getWin(), m_posy - 2, m_posx - 1, ". . .");
	mvwprintw(win.getWin(), m_posy - 1, m_posx, "\\|/");
	mvwprintw(win.getWin(), m_posy, m_posx - 2, "`--+--'");
	mvwprintw(win.getWin(), m_posy + 1, m_posx, " /|\\ ");
	mvwprintw(win.getWin(), m_posy + 2, m_posx - 1, "' | '");
	refresh();
	usleep(100);
}

void					AObject::move(Window& win)
{
	if (m_hp > 0)
	{
		if (m_posy > win.getY())
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