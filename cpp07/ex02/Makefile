# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 09:50:43 by awilliam          #+#    #+#              #
#    Updated: 2024/10/23 15:55:19 by awilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ArrayExercise

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJ): $(SRC)
	@echo "\033[1;36mCreating object files..."
	@c++ $(FLAGS) -c $(SRC)
	@echo "\033[0;32mDONE\n"

$(NAME): $(OBJ)
	@echo "\033[1;36mCompiling executable..."
	@c++ $(FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;32mDONE\n"


clean: 
	@echo "\033[1;36mCleaning object files..."
	@rm -f $(OBJ)
	@echo "\033[0;32mDONE\n"

fclean: clean
	@echo "\033[1;36mCleaning executable..."
	@rm -f $(NAME)
	@echo "\033[0;32mDONE\n"

re: clean all