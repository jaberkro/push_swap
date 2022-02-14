# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/14 15:12:40 by jaberkro      #+#    #+#                  #
#    Updated: 2022/02/14 15:46:14 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = ft_push_swap.c
OBJ = $(SRC:.c=.o)

BNAME = checker
BSRC = ft_checker.c
BOBJ = $(BSRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
all: $(NAME) $(BNAME)
else
all: $(NAME)
endif

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(BNAME): $(BOBJ)
	gcc $(FLAGS) $(BOBJ) -o $(BNAME)

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean re
