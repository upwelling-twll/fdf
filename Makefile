NAME = fdf

CC = cc

FLAGS = #-Wall -Wextra -Werror 

RM = rm -f

SRC = main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: 
		@ $(RM) $(OBJ)

fclean: clean
		@ $(RM) $(NAME)

re: fclean all