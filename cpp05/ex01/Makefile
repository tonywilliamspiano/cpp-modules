# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 18:46:46 by awilliam          #+#    #+#              #
#    Updated: 2024/08/02 15:12:40 by awilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC = Bureaucrat.cpp main.cpp Form.cpp
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