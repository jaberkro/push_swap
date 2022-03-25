/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort_bitwise.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 10:37:30 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 11:02:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_bitwise(t_dlist **stack_a)
{
	int		i;
	int		j;
	int		len;
	t_dlist	*stack_b;

	i = 0;
	stack_b = NULL;
	len = ft_dlstlen(*stack_a);
	while (i < 10)
	{
		j = 0;
		if (check_sorted(*stack_a, 1) == 1 && stack_b == NULL)
			return ;
		while (j < len)
		{
			if ((((*stack_a)->val >> i) & 1) == 0)
				ps_pb(&stack_b, stack_a);
			else
				ps_ra(stack_a);
			j++;
		}
		while (stack_b)
			ps_pa(stack_a, &stack_b);
		i++;
	}
}
