# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 12:34:29 by awilliam          #+#    #+#              #
#    Updated: 2024/10/02 12:37:52 by awilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = TemplateFunctions

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