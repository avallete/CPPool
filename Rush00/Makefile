# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <avallete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 16:56:49 by avallete          #+#    #+#              #
#    Updated: 2015/06/20 04:56:54 by avallete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH:=./src/
SRC_NAME:=ft_retro.cpp\
			Window.cpp\
			EnnemyHorde.cpp\
			Player.cpp\
			Missile.cpp\
			AObject.cpp
CFLAGS=-Wall -Wextra -Werror
OBJ_PATH=./obj/
OBJ_NAME=$(SRC_NAME:.cpp=.o)
INC_PATH=./includes/
INC_NAME=ft_retro.hpp\
			Window.hpp\
			AObject.hpp\
			Player.hpp\
			Missile.hpp\
			EnnemyHorde.hpp
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
CFLAGS=-g -Wall -Wextra -Werror
CC=g++
NAME=ft_retro
RED=\033[30;41m
GREEN=\033[32m
CYAN=\033[36m
ORANGE=\033[33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) $(CFLAGS) $(OBJ) -I $(INC_PATH) -lncurses -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $(NAME) : $@ with $<${NC}";
	@$(CC) $(CFLAGS) -c $< -I $(INC_PATH) -o $@

clean:
	@echo "${RED} Delete OBJ files ${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${RED} Delete $(NAME) file ${NC}"
	@rm -rf $(NAME)

debug:
	@echo "${GREEN}Compile $(NAME) with -g $(CFLAGS)${NC}";
	@$(CC) -g $(CFLAGS) $(OBJ) -I $(INC_PATH) -lncurses -o $(NAME)

re:fclean all

.PHONY: all clean fclean re
