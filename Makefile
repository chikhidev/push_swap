NAME = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror
OPS_SRC = 	operations/push.c \
			operations/rotate.c \
			operations/swap.c \
			operations/r_rotate.c

SRC = 	manda/main.c \
		manda/error.c \
		manda/validation.c \
		manda/stack.c \
		manda/actions.c \
		manda/sort.c \
		manda/sort2.c \
		manda/sort3.c \
		manda/sort4.c

BSRC = bonus/main.c \
		bonus/error.c \
		bonus/stack.c

SRC += $(OPS_SRC)
OBJ = $(SRC:.c=.o)
BSRC += $(OPS_SRC)
BOBJ = $(BSRC:.c=.o)
LIBFT = libft.a
GNL = get_next_line.o

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m
ORANGE = \033[0;33m

all: $(NAME)
bonus: $(BONUS)
b: all clean
	@clear

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compiling $(NAME) 👾...$(RESET)"
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS): $(BOBJ) $(LIBFT) $(GNL)
	@echo "$(GREEN)Compiling $(BONUS) 👾...$(RESET)"
	@cc $(CFLAGS) $(BOBJ) $(GNL) $(LIBFT) -o $(BONUS)

$(LIBFT) :
	@echo "$(ORANGE)Compiling libft 🪼...$(RESET)"
	@make -C libft all bonus && mv libft/libft.a .

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(GNL): get_next_line/get_next_line.c
	@echo "$(ORANGE)Compiling get_next_line 🪼...$(RESET)"
	@cc $(CFLAGS) -c get_next_line/get_next_line.c -o get_next_line.o

clean:
	@echo "$(RED)Cleaning object files 🌬...$(RESET)"
	@rm -f $(OBJ) $(LIBFT) $(GNL)
	@make -C libft clean

fclean: clean
	@echo "Full cleaning 🌪..."
	@rm -f $(NAME) $(BONUS)
