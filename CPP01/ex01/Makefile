# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 16:03:56 by miturk            #+#    #+#              #
#    Updated: 2024/10/14 13:20:10 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = main.cpp \
	Zombie.cpp \
	ZombieHorde.cpp

OBJ = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} -o ${NAME} $^

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re