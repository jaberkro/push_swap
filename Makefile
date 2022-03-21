# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/03/21 13:05:57 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
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

#SRC = ./src/ft_dlst/ft_dlstnew.c ./src/ft_dlst/ft_dlstadd_front.c \
	./src/ft_dlst/ft_dlstadd_back.c ./src/ft_dlst/ft_dlstrotate.c \
	./src/ft_dlst/ft_dlstrev_rotate.c ./src/ft_dlst/ft_dlstswap.c \
	./src/ft_dlst/ft_dlstpush.c ./src/ft_dlst/ft_dlstclear.c \
	./src/ft_dlst/ft_dlstlen.c ./src/ft_dlst/ft_dlstindex_lowest.c \
	./src/push_swap.c ./src/parsing.c ./src/commands.c ./src/sorting/quick_sort.c
#SRC = ft_dlstnew.c ft_dlstadd_front.c ft_dlstadd_back.c ft_dlstrotate.c \
	ft_dlstrev_rotate.c ft_dlstswap.c ft_dlstpush.c ft_dlstclear.c \
	ft_dlstlen.c ft_dlstindex_lowest.c push_swap.c parsing.c commands.c \
	quick_sort.c
#OBJ = $(SRC:.c=.o)

#BNAME = checker
#BSRC = ft_checker.c
#BOBJ = $(BSRC:.c=.o)

# COLORS
PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

#ifdef WITH_BONUS
#all: $(NAME) $(BNAME)
#else
all: $(NAME)
#endif

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	gcc $(FLAGS) $(OBJECTS) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)PUSH_SWAP$(RESET) :)"

#$(BNAME): $(BOBJ)
#	gcc $(FLAGS) $(BOBJ) $(LIBFT) $(INC) -o $(BNAME)
#	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)CHECKER$(RESET) :)"

#%.o: %.c
#	gcc -c $(FLAGS) $(INC) $< -o $@ 

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
