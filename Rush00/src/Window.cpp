#include "ft_retro.hpp"

Window::Window(void) : _color(0)
{
	initscr();
	m_win = stdscr;
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(m_win, m_sizey, m_sizex);
	nodelay(stdscr, TRUE);
	if (has_colors() == FALSE)
	{
		endwin();
		std::cout << "Color are not eneable in this term." << std::endl;
		exit(1);
	}
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

void	Window::setColor(int i)
{
	_color = i;
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

void	Window::printBorder()
{
	if (_color == 1)
	{
		start_color();
		init_pair(12,COLOR_GREEN,COLOR_GREEN);
		attron(COLOR_PAIR(12));
	}
	if (_color == 2)
	{
		start_color();
		init_pair(14,COLOR_RED,COLOR_RED);
		attron(COLOR_PAIR(14));
	}

	for (int i = 0; i < m_sizex; i++)
		mvprintw(getX(), i, "-");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(getY(), i, "-");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, 0, "|");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, getX(), "|");
	attroff(COLOR_PAIR(14));
	attroff(COLOR_PAIR(12));

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
