# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tony <tony@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 18:37:59 by tony              #+#    #+#              #
#    Updated: 2023/08/06 11:09:55 by tony             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc
GREEN = \033[0;32m
BLUE = \033[1;36m
RESET = \033[0m

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(OBJ): $(SRC)
	@echo "$(BLUE)Creating object files...$(RESET)"
	@c++ $(FLAGS) -c $(SRC)
	@echo "$(GREEN)DONE\n$(RESET)"

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling executable...$(RESET)"
	@c++ $(FLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)DONE\n$(RESET)"

clean: 
	@echo "$(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)DONE\n$(RESET)"

fclean: clean
	@echo "$(BLUE)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)DONE\n$(RESET)"

re: clean all