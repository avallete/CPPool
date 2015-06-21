#include "ft_retro.hpp"

int		get_difficult(int i)
{
	if (i == 0)
		return 10;
	else if (i == 1)
		return 30;
	else
		return 70;
}
void play(int i)
{
	i = get_difficult(i);
	Window win;
	Player		p(win);
	EnnemyHorde n = EnnemyHorde(i, "^v^");
	Missile miss = Missile(20, "|");
	n.randomPOP(win);
	int	input = 0;
	while (input != KEY_ECHAP && p.getHP() > 0)
	{
		clear();
		input = getch();
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
		while(getch() != ERR);
		usleep(60000);
	}
}

void	print_logo(Window win)
{
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(win.getY() / 6, win.getX() / 2 - (win.getX() / 3) , "  _____ _____        _____ ______           _____ ____  _   _  ____  _    _ ______ _____   ____  _____ ");
	mvprintw(win.getY() / 6 + 1, win.getX() / 2 - (win.getX() / 3), " / ____|  __ \\ /\\   / ____|  ____|         / ____/ __ \\| \\ | |/ __ \\| |  | |  ____|  __ \\ / __ \\|  __ \\ ");
	mvprintw(win.getY() / 6 + 2,  win.getX() / 2 - (win.getX() / 3), "| (___ | |__) /  \\ | |    | |__           | |   | |  | |  \\| | |  | | |  | | |__  | |__) | |  | | |__) |");
	mvprintw(win.getY() / 6 + 3,  win.getX() / 2 - (win.getX() / 3), " \\___ \\|  ___/ /\\ \\| |    |  __|          | |   | |  | | . ` | |  | | |  | |  __| |  _  /| |  | |  _  / ");
	mvprintw(win.getY() / 6 + 4,  win.getX() / 2 - (win.getX() / 3), " ____) | |  / ____ \\ |____| |____         | |___| |__| | |\\  | |__| | |__| | |____| | \\ \\| |__| | | \\ \\ ");
	mvprintw(win.getY() / 6 + 5, win.getX() / 2 - (win.getX() / 3) , "|_____/|_| /_/    \\_\\_____|______|         \\_____\\____/|_| \\_|\\___\\_\\_____/|______|_|  \\_\\_____/|_|  \\_\\ ");
	attroff(COLOR_PAIR(1));
}

void	print_menu(Window & win)
{
	int		input = 0;
	int		i = 0;
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_CYAN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_RED);
	nodelay(stdscr, FALSE);
	while(input != KEY_ECHAP)
	{
		clear();
		print_logo(win);
		attron(COLOR_PAIR(2));
		if (i == 0)
		{
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 9, win.getX() / 2 - (win.getX() / 5), " ______           _______     __");
			mvprintw(win.getY() / 4 + 10, win.getX() / 2 - (win.getX() / 5), "|  ____|   /\\    / ____\\ \\   / /");
			mvprintw(win.getY() /4 + 11, win.getX() / 2 - (win.getX() / 5), "| |__     /  \\  | (___  \\ \\_/ / ");
			mvprintw(win.getY() /4 + 12, win.getX() / 2 - (win.getX() / 5), "|  __|   / /\\ \\  \\___ \\  \\   /  ");
			mvprintw(win.getY() /4 + 13, win.getX() / 2 - (win.getX() / 5), "| |____ / ____ \\ ____) |  | |   ");
			mvprintw(win.getY() / 4 + 14, win.getX() / 2 - (win.getX() / 5), "|______/_/    \\_\\_____/   |_|   ");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		}
		else
		{
			mvprintw(win.getY() / 4 + 9, win.getX() / 2 - (win.getX() / 5), " ______           _______     __");
			mvprintw(win.getY() / 4 + 10, win.getX() / 2 - (win.getX() / 5), "|  ____|   /\\    / ____\\ \\   / /");
			mvprintw(win.getY() /4 + 11, win.getX() / 2 - (win.getX() / 5), "| |__     /  \\  | (___  \\ \\_/ / ");
			mvprintw(win.getY() /4 + 12, win.getX() / 2 - (win.getX() / 5), "|  __|   / /\\ \\  \\___ \\  \\   /  ");
			mvprintw(win.getY() /4 + 13, win.getX() / 2 - (win.getX() / 5), "| |____ / ____ \\ ____) |  | |   ");
			mvprintw(win.getY() / 4 + 14, win.getX() / 2 - (win.getX() / 5), "|______/_/    \\_\\_____/   |_|   ");
		}
		if (i == 1)
		{
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 16, win.getX() / 2 - (win.getX() / 5), " __  __ ______ _____ _____ _    _ __  __ ");
			mvprintw(win.getY() / 4 + 17, win.getX() / 2 - (win.getX() / 5), "|  \\/  |  ____|  __ \\_   _| |  | |  \\/  |");
			mvprintw(win.getY() / 4 + 18, win.getX() / 2 - (win.getX() / 5), "| \\  / | |__  | |  | || | | |  | | \\  / |");
			mvprintw(win.getY() / 4 + 19, win.getX() / 2 - (win.getX() / 5), "| |\\/| |  __| | |  | || | | |  | | |\\/| |");
			mvprintw(win.getY() / 4 + 20, win.getX() / 2 - (win.getX() / 5), "| |  | | |____| |__| || |_| |__| | |  | |");
			mvprintw(win.getY() / 4 + 21, win.getX() / 2 - (win.getX() / 5), "|_|  |_|______|_____/_____|\\____/|_|  |_|");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		}
		else
		{
			mvprintw(win.getY() / 4 + 16, win.getX() / 2 - (win.getX() / 5), " __  __ ______ _____ _____ _    _ __  __ ");
			mvprintw(win.getY() / 4 + 17, win.getX() / 2 - (win.getX() / 5), "|  \\/  |  ____|  __ \\_   _| |  | |  \\/  |");
			mvprintw(win.getY() / 4 + 18, win.getX() / 2 - (win.getX() / 5), "| \\  / | |__  | |  | || | | |  | | \\  / |");
			mvprintw(win.getY() / 4 + 19, win.getX() / 2 - (win.getX() / 5), "| |\\/| |  __| | |  | || | | |  | | |\\/| |");
			mvprintw(win.getY() / 4 + 20, win.getX() / 2 - (win.getX() / 5), "| |  | | |____| |__| || |_| |__| | |  | |");
			mvprintw(win.getY() / 4 + 21, win.getX() / 2 - (win.getX() / 5), "|_|  |_|______|_____/_____|\\____/|_|  |_|");
		}
		if (i == 2)
		{
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 23, win.getX() / 2 - (win.getX() / 5), " _    _          _____  _____  ");
			mvprintw(win.getY() / 4 + 24, win.getX() / 2 - (win.getX() / 5), "| |  | |   /\\   |  __ \\|  __ \\ ");
			mvprintw(win.getY() / 4 + 25, win.getX() / 2 - (win.getX() / 5), "| |__| |  /  \\  | |__) | |  | |");
			mvprintw(win.getY() / 4 + 26, win.getX() / 2 - (win.getX() / 5), "|  __  | / /\\ \\ |  _  /| |  | |");
			mvprintw(win.getY() / 4 + 27, win.getX() / 2 - (win.getX() / 5), "| |  | |/ ____ \\| | \\ \\| |__| |");
			mvprintw(win.getY() / 4 + 28, win.getX() / 2 - (win.getX() / 5), "|_|  |_/_/    \\_\\_|  \\_\\_____/ ");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		}
		else
		{
			mvprintw(win.getY() / 4 + 23, win.getX() / 2 - (win.getX() / 5), " _    _          _____  _____  ");
			mvprintw(win.getY() / 4 + 24, win.getX() / 2 - (win.getX() / 5), "| |  | |   /\\   |  __ \\|  __ \\ ");
			mvprintw(win.getY() / 4 + 25, win.getX() / 2 - (win.getX() / 5), "| |__| |  /  \\  | |__) | |  | |");
			mvprintw(win.getY() / 4 + 26, win.getX() / 2 - (win.getX() / 5), "|  __  | / /\\ \\ |  _  /| |  | |");
			mvprintw(win.getY() / 4 + 27, win.getX() / 2 - (win.getX() / 5), "| |  | |/ ____ \\| | \\ \\| |__| |");
			mvprintw(win.getY() / 4 + 28, win.getX() / 2 - (win.getX() / 5), "|_|  |_/_/    \\_\\_|  \\_\\_____/ ");
		}
		if (i == 3)
		{
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 30, win.getX() / 2 - (win.getX() / 5), " ________   _______ _______ ");
			mvprintw(win.getY() / 4 + 31, win.getX() / 2 - (win.getX() / 5), "|  ____\\ \\ / /_   _|__   __|");
			mvprintw(win.getY() / 4 + 32, win.getX() / 2 - (win.getX() / 5), "| |__   \\ V /  | |    | |   ");
			mvprintw(win.getY() / 4 + 33, win.getX() / 2 - (win.getX() / 5), "|  __|   > <   | |    | |   ");
			mvprintw(win.getY() / 4 + 34, win.getX() / 2 - (win.getX() / 5), "| |____ / . \\ _| |_   | |   ");
			mvprintw(win.getY() / 4 + 35, win.getX() / 2 - (win.getX() / 5), "|______/_/ \\_\\_____|  |_|   ");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		}
		else
		{
			mvprintw(win.getY() / 4 + 30, win.getX() / 2 - (win.getX() / 5), " ________   _______ _______ ");
			mvprintw(win.getY() / 4 + 31, win.getX() / 2 - (win.getX() / 5), "|  ____\\ \\ / /_   _|__   __|");
			mvprintw(win.getY() / 4 + 32, win.getX() / 2 - (win.getX() / 5), "| |__   \\ V /  | |    | |   ");
			mvprintw(win.getY() / 4 + 33, win.getX() / 2 - (win.getX() / 5), "|  __|   > <   | |    | |   ");
			mvprintw(win.getY() / 4 + 34, win.getX() / 2 - (win.getX() / 5), "| |____ / . \\ _| |_   | |   ");
			mvprintw(win.getY() / 4 + 35, win.getX() / 2 - (win.getX() / 5), "|______/_/ \\_\\_____|  |_|   ");

		}
		attroff(COLOR_PAIR(2));
		input = getch();
		if (input == 259)
		{
			i--;
			if (i == -1)
				i = 3;
		}
		else if (input == 258)
		{
			i++;
			if (i == 4)
				i = 0;
		}
		else if (input == 10)
		{
			if (i >=0 && i < 3)
				play( i);
			else
				return;
		}
		refresh();
		usleep(60000);
	}
}

void	menu(void)
{
	srand(time(NULL));
	Window win;
	clear();
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	print_logo(win);
	print_menu(win);
	attroff(COLOR_PAIR(1));
	refresh();
}


int main(void)
{
	menu();
}
