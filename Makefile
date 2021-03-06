SRC_DIR = src/
OBJ_DIR = bin/
INC_DIR = includes/
LIBFT_DIR = libft/

SRCS = ft_printf.c parser.c utils.c types.c buffer.c process_flags.c utils2.c types2.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I $(LIBFT_DIR)

NAME = libftprintf.a

LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	cd libft && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
