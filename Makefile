##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_passwd
##

MAIN_FILE = main.c	\

SRC	=	src/main_passwd.c\
		src/my_passwd.c\
		src/print_help.c\
		src/log_in.c\
		src/create_account.c\
		src/choice_exit.c\
		src/graphical/main_loop.c\

LIB_SRC	=	lib/my/my_putchar.c\
			lib/my/my_putstr.c\
			lib/my/my_strcmp.c\
			lib/my/my_strlen.c\
			lib/my/my_puterror.c\
			lib/my/my_str_concat.c\

OBJ	=	$(MAIN_FILE:.c=.o) $(SRC:.c=.o) $(LIB_SRC:.c=.o)

TEST_OBJ = ./tests/test_passwd.c

NAME	=	my_passwd

CFLAGS	= -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -I./include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests
	rm -f *.out

re:	fclean all

unit_tests:	fclean $(NAME)						#unit_tests rule
	gcc -o unit_tests $(SRC) $(LIB_SRC) $(TEST_OBJ) --coverage -lcriterion

tests_run:	unit_tests							#tests_run rule
	./unit_tests
