# VARIABLES
NAME = libftprintf.a
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(OBJ_DIR)/libft.a
INC_DIR = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

# SOURCE AND OBJECTS
LIBFT_SRCS = $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_strchr.c
LIBFT_OBJS = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/%.o)
SRCS =	$(SRC_DIR)/dec_to_hex.c $(SRC_DIR)/f_selector.c \
		$(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_putchar.c \
		$(SRC_DIR)/ft_putnum.c $(SRC_DIR)/ft_putptr.c \
		$(SRC_DIR)/ft_putstr.c $(SRC_DIR)/get_hex_digit.c \
		$(SRC_DIR)/put_unsigned_num.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(LIBFT_OBJS) $(OBJS)

$(LIBFT): $(LIBFT_OBJS)
	ar rcs $(LIBFT) $(LIBFT_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME)
	$(CC) $(CFLAGS) -o test/test_ft_printf.o -c test/test_ft_printf.c
	$(CC) $(CFLAGS) -o test/main.o -c test/main.c
	$(CC) $(CFLAGS) -o test/test_runner test/test_ft_printf.o test/main.o $(NAME)
	./test/test_runner

clean:
	rm -f $(OBJS) $(LIBFT_OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	rm -f test/*.o test/test_runner ft_output.txt orig_output.txt
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re