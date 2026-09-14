NAME = libft.a
SRCS = ft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS  = $(SRCS:.c=.o) 
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
all : $(NAME)
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean : 
	rm -f $(OBJS)
fclean : 
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re