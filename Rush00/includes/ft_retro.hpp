#ifndef FT_RETRO_HPP
#define FT_RETRO_HPP
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Window.hpp"
#include "AObject.hpp"
#include "EnnemyHorde.hpp"
#include "Player.hpp"
#include "Missile.hpp"
#define KEY_ECHAP 27
int     get_difficult(int i);
void    play(int i, Window& win);
void    print_logo(Window win);
void    print_menu(Window & win);
void    menu(void);
#endif