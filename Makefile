# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/02/14 16:14:23 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = ft_push_swap.c
OBJ = $(SRC:.c=.o)

BNAME = checker
BSRC = ft_checker.c
BOBJ = $(BSRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = libft.h 
LIBFT_DIR = libft/
LIBFT = libft/libft.a

# COLORS
PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

ifdef WITH_BONUS
all: $(NAME) $(BNAME)
else
all: $(NAME)
endif

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) ./$(NAME)
	gcc $(FLAGS) $(OBJ) -I $(INC) -o $(NAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)PUSH_SWAP$(RESET) :)"

$(BNAME): $(BOBJ)
	gcc $(FLAGS) $(BOBJ) -I $(INC) -o $(BNAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)CHECKER$(RESET) :)"

%.o: %.c
	gcc -c $(FLAGS) -I $(INC) -o $@ $<

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
