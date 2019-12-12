.PHONY: all clean fclean re

NAME = fillit

SRCS = build_tetris.c check_file.c check_grid.c fill_grid.c\
get_path.c main.c utils.c

OBJ = $(SRCS:.c=.o)

HDR = -I./

LIB_DIR = libft/

LIB_NAME = lft

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) $(OBJ) $(HDR) -L$(LIB_DIR) -$(LIB_NAME) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) $(HDR) -c  $< -o $@

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
