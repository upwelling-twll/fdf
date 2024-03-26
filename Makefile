UNAME_S = $(shell uname -s)

NAME = fdf

CC = cc

RM = rm -f

SRC = main.c parsing.c fdf_split.c save_map.c exit.c dbg_fdf.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

LIBS :=
ifeq ($(UNAME_S),Darwin) # MacOS
    FLAGS += -Imlx
    LIBS +=  -Lmlx -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S),Linux) # Linux
    FLAGS += -I/usr/include -Imlx_linux
    LIBS += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@ >/dev/null

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -g3 -fsanitize=address $(OBJ) $(LIBS) -o $(NAME) libft/*.o

libft:
	@ make -C libft/ >/dev/null

clean: 
		@ $(RM) $(OBJ)
		@ make -C libft/ clean >/dev/null

fclean: clean
		@ $(RM) $(NAME)
		@ make -C libft/ fclean >/dev/null

re: fclean all

.PHONY: all libft clean fclean re