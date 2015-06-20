#include "Window.hpp"

Window::Window(void)
{
	initscr();
	m_win = stdscr;
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(m_win, m_sizex, m_sizey);
	nodelay(stdscr, TRUE);
	return;
}

Window::Window(WINDOW* win): m_win(win) 
{
	getmaxyx(m_win, m_sizex, m_sizey);
	return;
}

Window::Window(Window const & src)
{
	*this = src;
	return;
}

Window::~Window(void)
{
	delwin(m_win);
	return;
}

int 	Window::getX(void) const
{
	return(m_sizex);
}

int 	Window::getY(void) const
{
	return(m_sizey);
}

WINDOW* Window::getWin(void) const
{
	return(m_win);
}

void 	Window::takeSize(void)
{
	getmaxyx(m_win, m_sizex, m_sizey);
}

Window& Window::operator=(Window const & rhs)
{
	m_sizex = rhs.getX();
	m_sizey = rhs.getY();
	m_win = rhs.getWin();
	return (*this);
}