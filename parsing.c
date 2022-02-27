/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/27 19:12:34 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/27 20:12:04 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_list(t_dlist *to_print)
{
	while (to_print)
	{
		ft_printf("<%d>", to_print->content);
		to_print = to_print->next;
	}
	ft_printf("\n");
}

int	error_check_and_make_dlist(char *input, t_dlist **stack_a)
{
	int		i;
	long	value;
	t_dlist	*new_element;

	i = 0;
	while (input[i])
	{
		if (ft_isdigit(input[i]) == 0 && (i != 0 || (i == 0 && \
			input[i] != '-' && input[i] != '+')))
			return (0);
		i++;
	}
	value = ft_atol(input);
	if (value < -2147483648 || value > 2147483647)
		return (0);
	new_element = ft_dlstnew((int)value);
	if (new_element == NULL)
	{
		ft_dlstclear(stack_a);
		return (0);
	}
	ft_dlstadd_back(stack_a, new_element);
	return (1);
}

int	parse_input(int argc, char **argv, t_dlist **stack_a)
{
	int		i;
	int		j;
	char	**input;

	i = 1;
	while (i < argc)
	{
		j = 0;
		input = ft_split(argv[i], ' ');
		if (input[0] == NULL)
			return (0);
		while (input[j])
		{
			if (error_check_and_make_dlist(input[j], stack_a) == 0)
				return (0);
			free(input[j]);
			j++;
		}
		free(input);
		i++;
	}
	return (1);
}

int	main(int argc, char**argv)
{
	t_dlist	*stack_a;

	if (argc == 1)
		return (0);
	if (parse_input(argc, argv, &stack_a) == 0)
		return (write(1, "Error\n", 6));
	print_list(stack_a);
	ft_dlstclear(&stack_a);
	system("leaks push_swap");
	return (0);
}
