# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <avallete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 16:56:49 by avallete          #+#    #+#              #
#    Updated: 2015/06/08 18:37:06 by avallete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH:=./src/
SRC_NAME:=Contact.class.cpp\
	Book.class.cpp\
	N3310.cpp
CFLAGS=-Wall -Wextra -Werror
OBJ_PATH=./obj/
OBJ_NAME=$(SRC_NAME:.cpp=.o)
INC_PATH=./includes/
INC_NAME=Contact.class.hpp\
	Book.class.hpp\
	N3310.h
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
CFLAGS=-Wall -Wextra -Werror
CC=g++
NAME=N3310
RED=\033[30;41m
GREEN=\033[32m
CYAN=\033[36m
ORANGE=\033[33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) $(CFLAGS) $(OBJ) -I $(INC_PATH) -o $(NAME)

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

.PHONY: all clean fclean re
