# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/03/25 14:02:05 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address -g
INC = -I ./include

LIBFT_DIR = libft/
LIBFT = libft/libft.a

SRC_DIR = src
BUILD_DIR = obj
SRC_EXT = c
OBJ_EXT = o

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.$(SRC_EXT)")
OBJS    := $(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(OBJS))

# COLORS
PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	gcc $(FLAGS) $(OBJECTS) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)PUSH_SWAP$(RESET) :)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $(INC) $^ -o $@

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ) $(BOBJ)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)Done $(GREEN)CLEANING$(YELLOW) PUSH_SWAP$(PINK) :)$(RESET)"

fclean: clean
	rm -f $(NAME) $(BNAME)
	@echo "$(RED)Done $(GREEN)FANCY CLEANING$(YELLOW) PUSH_SWAP$(PINK) :)$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
