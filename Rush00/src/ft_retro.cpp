#include "ft_retro.hpp"
#define SHIP "   /\\\n  /  \\\n /|/\\|\\\n/_||||_\\"

void play(void)
{
	Window win;
	Player		p(win);
	EnnemyHorde n = EnnemyHorde(100, "^v^");
	n.randomPOP(win);
	int	input = 0;
	while (input != KEY_ECHAP && p.getHP() > 0)
	{
		clear();
		input = getch();
		p.checkEnemies(n.getHorde(), n.getNumber(), win);
		win.takeSize();
		win.printBorder();
		n.printit(win);
		p.printit(win);
		p.inputDirection(input);
		wrefresh(win.getWin());
		p.move(win);
		p.printit(win);
		n.move(win);
		usleep(60000);
	}
}

int main(void)
{
	play();
	sleep(2);
}