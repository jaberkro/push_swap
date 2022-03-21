/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 13:10:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 14:26:44 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*bubble_sort(t_dlist *stack_a, int ascending)
{
	int	len;
	int	i;

	len = ft_dlstlen(stack_a);
	while (check_sorted(stack_a, ascending) == 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (((ascending == 1 && stack_a->val > stack_a->next->val) \
			|| (ascending == 0 && stack_a->val < stack_a->next->val)))
			{
				ps_sa(&stack_a);
				if (check_sorted(stack_a, ascending) == 1)
					return (stack_a);
			}
			ps_ra(&stack_a);
			if (check_sorted(stack_a, ascending) == 1)
				return (stack_a);
			i++;
		}
		ps_ra(&stack_a);
	}
	return (stack_a);
}
