#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "ft_retro.hpp"

class Window
{
	public:
		Window(void);
		Window(WINDOW* win);
		Window(Window const & src);
		~Window(void);
		void	takeSize(void);
		int		getX(void) const;
		int		getY(void) const;
		WINDOW*	getWin(void) const;

		Window& operator=(Window const & rhs);
	protected:
		int		m_sizex;
		int		m_sizey;
		WINDOW* m_win;
};
#endif