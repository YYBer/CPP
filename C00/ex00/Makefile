# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 21:50:09 by yli               #+#    #+#              #
#    Updated: 2023/08/01 22:13:28 by yli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRCS	= megaphone.cpp
OBJS	= $(SRC:.cpp=.o)

#Colors:
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m

all:	$(NAME)

$(NAME):
		@printf "$(GREEN) -Compiling $(NAME)... $(RESET)\n"
		@ $(CC) $(FLAGS) $(SRCS) -o $(NAME)
		@printf "$(GREEN) -Comiling finished. $(RESET)\n"

clean:
		@$(RM) $(OBJS)
		@printf "$(YELLOW) -Deleted .o files. $(RESET)\n"

fclean:	clean
		@$(RM) $(NAME)
		@printf "$(YELLOW) -Deleted all. $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
