# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 14:30:28 by miturk            #+#    #+#              #
#    Updated: 2024/10/29 11:41:44 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = 	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

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