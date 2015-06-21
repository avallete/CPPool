#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <ncurses.h>
#include <cstdlib>

class Window
{
	public:
		Window(void);
		Window(Window const & src);
		~Window(void);
		void	takeSize(void);
		int		getX(void) const;
		int		getY(void) const;
		WINDOW*	getWin(void) const;
		void	printBorder(void);

		Window& operator=(Window const & rhs);
		int 	m_red;
		int 	m_green;
		int 	m_yellow;
		int 	m_blue;
		int 	m_black;
		int 	m_grey;
		int 	m_orange;
	protected:
		int		m_sizex;
		int		m_sizey;
		WINDOW* m_win;
};
#endif