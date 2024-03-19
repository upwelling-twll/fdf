UNAME_S = $(shell uname -s)

NAME = fdf

CC = cc

RM = rm -f

SRC = main.c parsing.c dbg_fdf.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3 #-g -fsanitize=address

LIBS :=
ifeq ($(UNAME_S),Darwin) # MacOS
    FLAGS += -Imlx
    LIBS +=  -Lmlx -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S),Linux) # Linux
    FLAGS += -I/usr/include -Imlx_linux
    LIBS += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(OBJ) -fsanitize=address $(LIBS) -o $(NAME) libft/*.o

libft:
	@ make -C libft/

clean: 
		@ $(RM) $(OBJ)
		@ make -C libft/ clean

fclean: clean
		@ $(RM) $(NAME)
		@ make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re