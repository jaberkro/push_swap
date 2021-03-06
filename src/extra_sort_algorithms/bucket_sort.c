/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 15:04:58 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 16:13:37 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_next_two(t_dlist **stack_a, t_dlist **stack_b, int len, int part)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (((*stack_a)->val > len / 5 * (1 - part) && \
		(*stack_a)->val <= len / 5 * (3 + part)) && i < len)
		{
			if ((*stack_a)->val <= len / 5 * 2)
			{
				ps_pb(stack_b, stack_a);
				if ((*stack_b)->next && (*stack_b)->next->val > len / 5 * 2)
					ps_rb(stack_b);
			}
			else
			{
				ps_pb(stack_b, stack_a);
				if ((*stack_b)->next && (*stack_b)->val < (*stack_b)->next->val)
					ps_sb(stack_b);
			}
			i++;
		}
		ps_ra(stack_a);
		i++;
	}
}

void	bucket_sort(t_dlist **stack_a)
{
	int		len;
	int		i;
	t_dlist	*stack_b;

	stack_b = NULL;
	len = ft_dlstlen(*stack_a);
	i = 0;
	while (i < 2)
	{
		bucket_next_two(stack_a, &stack_b, len, i);
		i++;
	}
	bubble_sort(stack_a, 1);
	while (stack_b && stack_b->val)
		insertion_sort(stack_a, &stack_b);
	while (check_sorted(*stack_a, 1) == 0)
		ps_rra(stack_a);
}

/* Bucketsort puts the numbers in 5 buckets (buckets 1-4 in stack b, 
	bucket 5 stays in stack a. 5 will be sorted with bubble sort.
	4-1 get added using insertion sort*/
