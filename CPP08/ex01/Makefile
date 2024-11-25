# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 16:34:44 by wagons            #+#    #+#              #
#    Updated: 2024/11/25 12:46:15 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =	main.cpp \
		Span.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re