#include "ft_retro.hpp"

Window::Window(void)
{
	initscr();
	m_win = stdscr;
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(m_win, m_sizey, m_sizex);
	nodelay(stdscr, TRUE);
	return;
}

Window::Window(Window const & src)
{
	*this = src;
	return;
}

Window::~Window(void)
{
	endwin();
	return;
}

int 	Window::getX(void) const
{
	return(m_sizex - 1);
}

int 	Window::getY(void) const
{
	return(m_sizey - 1);
}

WINDOW* Window::getWin(void) const
{
	return(m_win);
}

void	Window::printBorder(void)
{
	for (int i = 0; i < m_sizex; i++)
		mvprintw(getX(), i, "-");	
	for (int i = 0; i < m_sizex; i++)
		mvprintw(getY(), i, "-");	
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, 0, "-");	
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, getX(), "-");	
}

void 	Window::takeSize(void)
{
	getmaxyx(m_win, m_sizey, m_sizex);
	printBorder();
}

Window& Window::operator=(Window const & rhs)
{
	m_sizex = rhs.getX() + 1;
	m_sizey = rhs.getY() + 1;
	m_win = rhs.getWin();
	return (*this);
}