##
## EPITECH PROJECT, 2023
## secured
## File description:
## Infos
##

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_putstr.c 	\
			lib/my_printf.c		\
			lib/my_putchar.c	\
			lib/my_put_nbr.c 	\
			lib/my_put_nbr_recursive.c	\

SRCNAME	=	main.c	\
			secured.c \


LIB = 	libhashtable.a

OBJLIB	=	$(SRCLIB:.c=.o)
OBJNAME	=	$(SRCNAME:.c=.o)

NAME	=	a.out

$(NAME) : $(LIB) $(OBJNAME)
	gcc -o $(NAME) $(OBJNAME) -lhashtable -L./ -g3

$(LIB) : $(OBJLIB)
	ar rc libhashtable.a lib/*.o


all:	$(LIB) $(NAME)

clean:
	rm -f $(OBJLIB) $(OBJNAME) libhashtable.a

fclean: clean
	rm -f $(NAME)

re: 	fclean all
