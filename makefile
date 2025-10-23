# Makefile

NAME = sokoban

SRCS = main.c \
	fonction.c 


all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all