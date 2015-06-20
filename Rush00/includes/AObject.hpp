#ifndef A_OBJECT_HPP
#define A_OBJECT_HPP
#include <unistd.h>
#include "Window.hpp"
#include <string>

class AObject
{
	public:
								AObject(void);
								AObject(int posx, int posy, int dirx, int diry, int speed, int hp, std::string form);
								AObject(AObject const & src);
								~AObject(void);
		int 					getX(void) const;
		int 					getY(void) const;
		int 					getdirX(void) const;
		int 					getdirY(void) const;
		int 					getSpeed(void) const;
		int						getsizeX(void) const;
		int						getsizeY(void) const;
		std::string&			getForm(void) const;
		int						getHP(void) const;
		void					setPos(int x, int y);
		void					setDir(int x, int y);
		void					setSpeed(int s);
		void					setForm(std::string form);
		void					move(Window& win);
		virtual void			printit(Window& win) const;
		virtual void			colision(AObject& obj);

		AObject& operator=(AObject const & rhs);
	protected:
		int			m_posx;
		int			m_posy;
		int			m_dirx;
		int			m_diry;
		int			m_speed;
		int			m_sizex;
		std::string	m_form; 
		int			m_hp;
};
#endif