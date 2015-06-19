#ifndef A_OBJECT_HPP
#define A_OBJECT_HPP
#include "IObject.hpp"

class AObject: public IObject
{
	public:
						AObject(void);
						AObject(AObject const & src);
						~AObject(void);
		int 			getposX(void) const;
		int 			getposY(void) const;
		int 			getdirX(void) const;
		int 			getdirY(void) const;
		int 			getSpeed(void) const;
		int				getsizeX(void) const;
		int				getsizeY(void) const;
		std::string&	getForm(void) const;
		int				getHP(void) const;
		void			move(void);

		AObject& operator=(AObject const & rhs);
	protected:
		int			m_posx;
		int			m_posy;
		int			m_dirx;
		int			m_diry;
		int			m_speed;
		int			m_sizex;
		int			m_sizey;
		std::string	m_form; 
		int			m_hp;
};
#endif