# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 15:44:24 by agan              #+#    #+#              #
#    Updated: 2024/03/14 15:44:24 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account
SRCS	= Account.cpp tests.cpp
OBJS 	= ${SRCS:.cpp=.o}
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -fr

#------------------------------------------------------------------------

# colours
GREEN = \033[0;32m
B_GREEN = \033[1;32m
BROWN = \033[0;33m
B_BROWN = \033[1;33m
END = \033[0m

#------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -fr $(OBJS)

fclean: clean
	@rm -fr $(NAME)
	@echo "$(B_GREEN)fclean completed$(END)"

re: fclean all

.cpp.o:
	@${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}
	@echo "$(B_GREEN)$< compiled.$(END)"

.PHONY: all clean fclean re
