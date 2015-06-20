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
	protected:
		int		m_sizex;
		int		m_sizey;
		WINDOW* m_win;
};
#endif