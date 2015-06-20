#include "ft_retro.hpp"
#define SHIP "   /\\\n  /  \\\n /|/\\|\\\n/_||||_\\"

void play(void)
{
	Window win;
	Player		p(win);
	EnnemyHorde n = EnnemyHorde(30, "^v^");
	Missile miss = Missile(20, "|");
	n.randomPOP(win);
	int	input = 0;
	while (input != KEY_ECHAP && p.getHP() > 0)
	{
		clear();
		input = getch();
		while (getch() != ERR);
		miss.activate(p.getX(), p.getY(), input);
		miss.checkDamages(n.getHorde(), n.getNumber(), win);
		p.checkEnemies(n.getHorde(), n.getNumber(), win);
		win.takeSize();
		win.printBorder();
		n.printit(win);
		miss.move(win);
		miss.printit(win);
		p.printit(win);
		p.inputDirection(input);
		wrefresh(win.getWin());
		p.move(win);
		p.printit(win);
		n.move(win);
		usleep(45000);
	}
}

int main(void)
{
	play();
	sleep(2);
}
