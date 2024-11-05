
NAME = so_long
User = $(shell whoami)

CC = $(shell which clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX_DIR = ./MLX42/
LIBFT_DIR = ./Libft/
SRC_DIR = ./utils/
INCLUDE_DIR = ./include/

MLX = $(MLX_DIR)build/libmlx42.a

LINK = -ldl -lglfw -pthread -lm

LIBFT = $(LIBFT_DIR)/libft.a

SRC =	$(SRC_DIR)player.c \
		$(SRC_DIR)map.c \
		$(SRC_DIR)duplicate_map.c \
		$(SRC_DIR)flood_fill.c \
		$(SRC_DIR)ft_error.c \
		$(SRC_DIR)init_mlx.c \
		$(SRC_DIR)move.c \
		main.c \

OBJS = $(SRC:.c=.o)

HEADERS = -I/usr/include -Imlx -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(LINK)
	@echo "COMPILING SO_LONG"

clean:
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@echo "CLEANING OBJECT FILES"

fclean: clean
	@rm -f $(NAME)
	@echo "REMOVING EXECUTABLE"

re: fclean all

.PHONY: all clean fclean re