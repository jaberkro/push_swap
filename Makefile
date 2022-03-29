# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/03/29 19:34:37 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
INC = -I ./include

LIBFT_DIR = libft/
LIBFT = libft/libft.a

SRC_DIR = src
BUILD_DIR = obj

SRC = src/commands_print.c src/commands_push_swap.c src/commands_rotate.c \
	src/parsing.c src/push_swap.c src/sort_radix_bitwise.c \
	src/sort_smallest.c src/ft_dlst/ft_dlstadd_back.c \
	src/ft_dlst/ft_dlstadd_front.c src/ft_dlst/ft_dlstclear.c \
	src/ft_dlst/ft_dlstindex_lowest.c src/ft_dlst/ft_dlstlast.c \
	src/ft_dlst/ft_dlstlen.c src/ft_dlst/ft_dlstnew.c \
	src/ft_dlst/ft_dlstpush.c src/ft_dlst/ft_dlstrev_rotate.c \
	src/ft_dlst/ft_dlstrotate.c src/ft_dlst/ft_dlstswap.c \
	src/extra_sort_algorithms/bubble_sort.c \
	src/extra_sort_algorithms/bucket_sort.c \
	src/extra_sort_algorithms/insertion_sort.c \
	src/extra_sort_algorithms/radix_sort_decimal.c

OBJ = $(subst $(SRC_DIR),$(BUILD_DIR), ${SRC:.c=.o})

# COLORS
PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	mkdir $(BUILD_DIR)/ft_dlst
	mkdir $(BUILD_DIR)/extra_sort_algorithms

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) $(INC) -c $^ -o $@

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) ./$(NAME)
	gcc $(FLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)PUSH_SWAP$(RESET) :)"

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)Done $(GREEN)CLEANING$(YELLOW) PUSH_SWAP$(PINK) :)$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Done $(GREEN)FANCY CLEANING$(YELLOW) PUSH_SWAP$(PINK) :)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
