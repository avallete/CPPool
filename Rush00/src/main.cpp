#include "main.hpp"
#define SHIP "   /\\\n  /  \\\n /|/\\|\\\n/_||||_\\"

int main(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getch();
	endwin();
}