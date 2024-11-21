NAME = so_long
User = $(shell whoami)

CC = $(shell which clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX_DIR = ./MLX42/build/
LIBFT_DIR = ./Libft/
SRC_DIR = ./utils/
INCLUDE_DIR = ./include/

MLX = $(MLX_DIR)/libmlx42.a

LINK = -ldl -lglfw -pthread -lm

LIBFT = $(LIBFT_DIR)/libft.a

SRC =	$(SRC_DIR)check.c\
		$(SRC_DIR)create_game.c \
		$(SRC_DIR)error.c \
		$(SRC_DIR)moves.c \
		$(SRC_DIR)moving.c \
		$(SRC_DIR)flood_fill.c \
		$(SRC_DIR)map.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)utils2.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)get_next_line_bonus.c \
		$(SRC_DIR)get_next_line_utils_bonus.c \

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
	@rm -f *.o
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "CLEANING OBJECT FILES"

fclean: clean
	@rm -f $(NAME)
	@echo "REMOVING EXECUTABLE"

re: fclean all

.PHONY: all clean fclean re