/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/29 17:45:06 by jaberkro      ########   odam.nl         */
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
		return (write(1, "Error\n", 6));
	}
	len = ft_dlstlen(stack_a);
	if (len <= 6)
		smallest_sort(&stack_a);
	else
		radix_sort_bitwise(&stack_a);
	write_command_to_terminal("end");
	return (0);
}

/* In case you want to try other sorting algorithms: 
	change radix_sort_bitwise(&stack_a); into one of these:
		bubble_sort(&stack_a, 1); 			// 100: 9000-12000	500: +290000
		bucket_sort(&stack_a); 				// 100: 900-1200 	500: +19000
		radix_sort_decimal(&stack_a, 4);	// 100: 1101 		500: KO
		radix_sort_bitwise(&stack_a);		// 100: 1063-1073	500: 6754-6764
	Function print_dlist is for debugging purposes */