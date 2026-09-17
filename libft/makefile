# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/14 15:19:22 by ketmoss           #+#    #+#              #
#    Updated: 2026/09/17 12:16:03 by ketmoss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS  = $(SRCS:.c=.o) 
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re