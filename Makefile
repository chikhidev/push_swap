NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
OPS_SRC = 	operations/push.c \
			operations/rotate.c \
			operations/swap.c \
			operations/r_rotate.c

SRC = 	manda/main.c \
		manda/error.c \
		manda/validation.c \
		manda/stack.c \
		manda/sort.c

SRC += $(OPS_SRC)
OBJ = $(SRC:.c=.o)
LIBFT = libft.a

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m
ORANGE = \033[0;33m

all: $(NAME)
b: all clean

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compiling $(NAME) 👾...$(RESET)"
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@echo "$(ORANGE)Compiling libft 🪼...$(RESET)"
	@make -C libft all bonus && mv libft/libft.a .

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files 🌬...$(RESET)"
	@rm -f $(OBJ) $(LIBFT)
	@make -C libft clean

fclean: clean
	@echo "Full cleaning $(NAME) 🌪..."
	@rm -f $(NAME)