.PHONY: all clean fclean re make_lib remake_lib

NAME = fillit

SRCS = check_file.c check_grid.c utils.c fill_grid.c get_path.c tetri_list.c main.c

OBJ = $(SRCS:.c=.o)

HDR = fillit.h

LIB_DIR = libft

LIB = lft

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS) $(HDR) make_lib
	$(CC) $(FLAGS) $(SRCS) -L$(LIB_DIR) -$(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

make_lib:
	make -C $(LIB_DIR)

remake_lib:
	make -C $(LIB_DIR) re