# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/02/14 15:36:20 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = ft_push_swap.c 

BNAME = checker
BSRC = ft_checker.c

FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
all: $(NAME) $(BNAME)
else
all: $(NAME)
endif

$(NAME): $(SRC)
	gcc -c $(FLAGS) $(SRC) -o $(NAME)

$(BNAME): $(BSRC)
	gcc -c $(FLAGS) $(BSRC) -o $(BNAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean re
