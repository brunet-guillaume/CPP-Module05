# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 14:06:15 by gbrunet           #+#    #+#              #
#    Updated: 2024/03/26 10:57:46 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

OBJ = main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all
