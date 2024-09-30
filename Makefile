NAME = 
User = $(shell whoami)

cc = $(shell wich clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror  \ -g -fsanitize=address,undefined \

MLX_DIR = ./MLX42/build
MLX = $(MLX_DIR)/libmlx_(UNAME).a
LINK =  -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR = 
SRC_DIR =

HEADERS = -I/usr/include -Imlx

SRC =

OBJS = $(SRC:.c=.o)

all: mlx42 $(NAME)

mlx42:
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LINK) $(HEADERS)
	@echo "COMPILING SO_LONG"

clean: @rm -rf(OBJS)
	@rm -rf $(_DIR)/*.o
	@echo "CLEANING SO_LONG"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)/libmlx42.a
	@echo "REMOVING SO_LONG"

re: fclean all
	@echo "REMAKING SO_LONG"

.PHONY: all clean fclean re
	@echo "PHONY SO_LONG"