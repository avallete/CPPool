#include "ft_retro.hpp"
#define SHIP "   /\\\n  /  \\\n /|/\\|\\\n/_||||_\\"

int main(void)
{
	AObject* ennem = new AObject[10];
	for (int i = 0; i < 10; i++)
	{
		ennem[i].setForm("V");
		ennem[i].setPos((rand() % 10), (rand() % 10));

	}
	while (1)
	{
		Window win;
		for (int i = 0; i < 10; i++)
		{
			mvprintw(ennem[i].getX(), ennem[i].getY(), ennem[i].getForm().data());
		}
		refresh();
		getch();
	}
	endwin();
}