# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tony <tony@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:09:02 by awilliam          #+#    #+#              #
#    Updated: 2023/07/24 18:26:50 by tony             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Internship

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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