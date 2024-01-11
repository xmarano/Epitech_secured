##
## EPITECH PROJECT, 2023
## B-CPE-110-MAR-1-1-secured-leo.gregori
## File description:
## main.c
##

SRC		=	lib/my_atoi.c 		\
			lib/my_putstr.c 	\
			lib/my_printf.c		\
			lib/my_putchar.c	\
			lib/my_put_nbr.c 	\
			lib/my_put_nbr_recursive.c	\
			secured.c 			\

OBJ		=	$(SRC:.c=.o)

LIB		=	ar rc libhashtable.a $(OBJ)

NAME	=	gcc main.c -L. -lhashtable

all		:	$(OBJ)
			$(LIB)

exe		:
			$(NAME)

clean 	:
			rm $(OBJ)

fclean 	:	clean
			rm -f libhashtable.a
			rm -f a.out

re		:	fclean all exe
