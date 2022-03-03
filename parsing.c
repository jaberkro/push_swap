/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/27 19:12:34 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 18:12:49 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_nested_array(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (0);
}

static int	index_dlist(t_dlist **stack_a)
{
	int	value;
	int	i;

	i = ft_dlstlen(*stack_a);
	value = -2147483648;
	while (i > 0)
	{
		value = ft_dlstindex_lowest(stack_a, value);
		if (value == 0)
			return (0);
		i--;
	}
	while ((*stack_a)->next)
	{
		(*stack_a)->content += 2147483649;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->content += 2147483649;
	while ((*stack_a)->previous)
		*stack_a = (*stack_a)->previous;
	return (1);
}

static int	error_check_and_make_dlist(char *input, t_dlist **stack_a)
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
		return (0);
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
			return (free_nested_array(input));
		while (input[j])
		{
			if (error_check_and_make_dlist(input[j], stack_a) == 0)
				return (free_nested_array(input));
			j++;
		}
		free_nested_array(input);
		i++;
	}
	if (index_dlist(stack_a) == 0)
		return (0);
	return (1);
}
