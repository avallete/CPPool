#include "AObject.hpp"

AObject::AObject(void):	m_posx(0), m_posy(0), m_dirx(0), m_diry(0), m_speed(0), 
						m_sizex(0), m_sizey(0), m_form(""), m_hp(0)
{
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

int 			AObject::getposX(void) const
{
	return (m_posx);
}

int 			AObject::getposY(void) const
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

int				AObject::getsizeY(void) const
{
	return (m_sizey);
}

std::string&	AObject::getForm(void) const
{
	return ((std::string&)m_form);
}

void			AObject::move(void)
{
	return;
}

AObject& AObject::operator=(AObject const & rhs)
{
	m_posx = rhs.getposX();
	m_posy = rhs.getposY();
	m_dirx = rhs.getdirX();
	m_diry = rhs.getdirY();
	m_speed = rhs.getSpeed(); 
	m_sizex = rhs.getsizeX();
	m_sizex = rhs.getsizeY();
	m_form = rhs.getForm();
	m_hp = rhs.getHP();
	return (*this);
}