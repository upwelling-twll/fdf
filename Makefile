UNAME_S = $(shell uname -s)

NAME = fdf

CC = cc

RM = rm -f

SRC = main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

LIBS :=
ifeq ($(UNAME_S),Darwin) # MacOS
    FLAGS += -Imlx
    LIBS += -Lmlx -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S),Linux) # Linux
    FLAGS += -I/usr/include -Imlx_linux
    LIBS += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -fsanitize=address $(LIBS) -o $(NAME)

clean: 
		@ $(RM) $(OBJ)

fclean: clean
		@ $(RM) $(NAME)

re: fclean all