#include "ft_retro.hpp"

int		hight_score = 0;

int		get_difficult(int i)
{
	if (i == 0)
		return 30;
	else if (i == 1)
		return 100;
	else
		return 300;
}

void	print_die(Window & win, Player p)
{
	start_color();
	init_pair(6 ,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(6));
	
	mvprintw( win.getY() / 3 + win.getY() / 12 , win.getX() / 3 + win.getX() / 16, "RRRRRRRRRRRRRRRRR           IIIIIIIIII        PPPPPPPPPPPPPPPPP   ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 1 , win.getX() / 3 + win.getX() / 16, "R::::::::::::::::R          I::::::::I        P::::::::::::::::P  ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 2, win.getX() / 3 + win.getX() / 16, "R::::::RRRRRR:::::R         I::::::::I        P::::::PPPPPP:::::P");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 3, win.getX() / 3 + win.getX() / 16, "RR:::::R     R:::::R        II::::::II        PP:::::P     P:::::P");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 4 , win.getX() / 3 + win.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P     P:::::P");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 5, win.getX() / 3 + win.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P     P:::::P");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 6, win.getX() / 3 + win.getX() / 16, "  R::::RRRRRR:::::R           I::::I            P::::PPPPPP:::::P ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 7, win.getX() / 3 + win.getX() / 16, "  R:::::::::::::RR            I::::I            P:::::::::::::PP  ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 8 , win.getX() / 3 + win.getX() / 16, "  R::::RRRRRR:::::R           I::::I            P::::PPPPPPPPP    ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 9, win.getX() / 3 + win.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 10, win.getX() / 3 + win.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 11, win.getX() / 3 + win.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 12, win.getX() / 3 + win.getX() / 16, "RR:::::R     R:::::R        II::::::II        PP::::::PP          ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 13, win.getX() / 3 + win.getX() / 16, "R::::::R     R:::::R ...... I::::::::I ...... P::::::::P          ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 14, win.getX() / 3 + win.getX() / 16, "R::::::R     R:::::R .::::. I::::::::I .::::. P::::::::P          ");
	mvprintw( win.getY() / 3 + win.getY() / 12 + 15, win.getX() / 3 + win.getX() / 16, "RRRRRRRR     RRRRRRR ...... IIIIIIIIII ...... PPPPPPPPPP          ");

	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvprintw(win.getY() / 3 + win.getY() / 12 + 20, win.getX() / 3 + win.getX() / 7 - 8, "SCORE :" );
	std::string		str;
	str = std::to_string(p.getScore());
	mvprintw(win.getY() / 3 + win.getY() / 12 + 20, win.getX() / 3 + win.getX() / 7, str.c_str());
	attroff(COLOR_PAIR(19));

	refresh();
	attroff(COLOR_PAIR(6));
	sleep(2);
}


void	play(int i, Window& win)
{
	nodelay(stdscr, TRUE);
	i = get_difficult(i);
	Player		p(win);
	EnnemyHorde n = EnnemyHorde(i, "^v^");
	Missile miss = Missile(10, "|");
	Rocket rock = Rocket(2, "[]");
	n.randomPOP(win);
	int	input = 0;
	p.setScoreZero();
	while (input != KEY_ECHAP && p.getHP() > 0)
	{
		clear();
		miss.print_score(win);
		win.takeSize();
		win.printBorder();
		input = getch();
		miss.activate(p.getX(), p.getY(), input);
		rock.activate(p.getX(), p.getY(), input);
		miss.checkDamages(n.getHorde(), n.getNumber(), win);
		rock.checkDamages(n.getHorde(), n.getNumber(), win);
		p.checkEnemies(n.getHorde(), n.getNumber(), win);
		p.print_life(win);
		miss.print_chargeur(win);
		rock.print_chargeur(win);
		if (p.getHP() > 0)
		{
			n.printit(win);
			miss.move(win);
			rock.move(win);
			miss.printit(win);
			rock.printit(win);
			p.printit(win);
			p.inputDirection(input);
			wrefresh(win.getWin());
			p.move(win);
			p.printit(win);
			n.move(win);
		}
		while(getch() != ERR);
		usleep(60000);
	}
	if (p.getHP() <= 0)
	{
		clear();
		print_die(win, p);
	}
	 if (p.getScore() > hight_score)
		 hight_score = p.getScore();

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


void		print_score(Window & win)
{
	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvwprintw(win.getWin(), 1, 2, "HIGHT SCORE :" );
	std::string		str;
	str = std::to_string(hight_score);
	mvwprintw(win.getWin(), 1, 16, str.c_str());
	attroff(COLOR_PAIR(19));
	refresh();
}



void	print_menu(Window & win)
{
	int		input = 0;
	int		i = 0;

	while (getch() != ERR);
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_RED);
	while(input != KEY_ECHAP)
	{
		nodelay(stdscr, FALSE);
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
		print_score(win);
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
				play(i, win);
			else
				return;
		}
		refresh();
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
	print_score(win);
	print_logo(win);
	print_menu(win);
	attroff(COLOR_PAIR(1));
	refresh();
}


int main(void)
{
	menu();
}
