/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 13:09:36 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_dlist(t_dlist *to_print)
{
	while (to_print)
	{
		ft_printf("<%d>", to_print->val);
		to_print = to_print->next;
	}
	ft_printf("\n");
}

int	check_sorted(t_dlist *stack, int ascending)
{
	int	last;

	last = stack->val;
	if (ascending == 1)
		last = 0;
	else
		last = 2147483647;
	while (stack)
	{
		if ((ascending == 1 && stack->val > last) || \
			(ascending == 0 && stack->val < last))
			last = stack->val;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char**argv)
{
	t_dlist	*stack_a;
	int		len;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (parse_input(argc, argv, &stack_a) == 0)
	{
		ft_dlstclear(&stack_a);
		system("leaks push_swap");
		return (write(1, "Error\n", 6));
	}
	len = ft_dlstlen(stack_a);
	if (ft_dlstlen(stack_a) <= 6)
		smallest_sort(&stack_a, 1);
	else
		radix_sort_bitwise(&stack_a);
	write_command_to_terminal("end");
	return (0);
}

/* Function print_dlist is for debugging purposes */