#include "AObject.hpp"

AObject::AObject(void):	m_posx(0), m_posy(0), m_dirx(0), m_diry(0), m_speed(0), 
m_sizex(0), m_form(""), m_hp(0)
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