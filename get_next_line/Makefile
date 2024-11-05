NAME = get_next_line_bonus.a

CC = $(shell which clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address,undefined


SRC_BONUS = get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus