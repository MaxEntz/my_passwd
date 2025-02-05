##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_passwd
##

SRC	=	main.c\
		src/main_passwd.c\
		src/my_passwd.c\
		src/print_help.c\
		src/log_in.c\
		src/create_account.c\
		src/choice_exit.c\

LIB_SRC	=	lib/my/my_putchar.c\
			lib/my/my_putstr.c\
			lib/my/my_strcmp.c\
			lib/my/my_strlen.c\

OBJ	=	$(SRC:.c=.o) $(LIB_SRC:.c=.o)

NAME	=	my_passwd

CFLAGS	= -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -I./include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all