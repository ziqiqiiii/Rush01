SRCS =  ./my_extra_func.c ./main.c
#$(addprefix ./srcs/, ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c)

OBJ = $(SRCS:%.c=%.o)

CC = gcc -Wall -Wextra -Werror

INCL = -I ./rush01.h

all: $(OBJ)
	$(CC) -o  rush.out $(OBJ)
%.o: %.c
	$(CC) -c $< -o $@ $(INCL)
%:
	$(CC) -o  rush.out main.c my_extra_func.c
	./rush.out "$@"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./rush.out

re: fclean all