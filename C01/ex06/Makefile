# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 20:52:48 by yli               #+#    #+#              #
#    Updated: 2023/08/29 19:38:22 by yli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= harlFilter

CC 		= c++
FLAGS 	= -Wall -Wextra -Werror -std=c++98
RM 		= rm -rf

SRCS 	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

#Colors:
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m

all:	$(NAME)

$(NAME):$(OBJS)
		@printf "$(GREEN) -Compiling $(NAME)... $(RESET)\n"
		@ $(CC) $(FLAGS) $(SRCS) -o $(NAME)
		@printf "$(GREEN) -Compiling finished. $(RESET)\n"

clean:
		@$(RM) $(OBJS)
		@printf "$(YELLOW) -Deleted .o files. $(RESET)\n"

fclean:	clean
		@$(RM) $(NAME)
		@printf "$(YELLOW) -Deleted all. $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
