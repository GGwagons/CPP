# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:56:47 by miturk            #+#    #+#              #
#    Updated: 2024/09/24 18:14:39 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
AR = ar rcs
RM = rm -f

SRC = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)

%.o:%.cpp
	$(CXX) $(FLAGS) -cpp $< -o $@

all: $(NAME)

$NAME: $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re