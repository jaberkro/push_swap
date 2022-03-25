/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 20:52:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 16:09:09 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	if ((*stack_b)->next && (*stack_b)->val < (*stack_b)->next->val)
		ps_sb(stack_b);
	if ((*stack_b)->val > (*stack_a)->val)
	{
		while ((*stack_b)->val > (*stack_a)->val)
			ps_ra(stack_a);
	}
	else if ((*stack_b)->val < (*stack_a)->val && (*stack_b)->val < \
	ft_dlstlast(*stack_a)->val && (*stack_a)->val - (*stack_b)->val > \
	ft_dlstlast(*stack_a)->val - (*stack_b)->val)
	{
		while ((*stack_b)->val < (*stack_a)->val && (*stack_b)->val < \
		ft_dlstlast(*stack_a)->val && (*stack_a)->val - (*stack_b)->val > \
		ft_dlstlast(*stack_a)->val - (*stack_b)->val)
			ps_rra(stack_a);
	}
	ps_pa(stack_a, stack_b);
	return ;
}

/*  Insertion_sort first rotates stack a to the right spot 
    before it inserts an element to the list (from stack b) */