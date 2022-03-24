/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 20:52:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 12:10:06 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_dlist **stack_a, int len)
{
	int	i;

	i = 0;
	len += 0;
	while ((*stack_a)->next && (*stack_a)->val > (*stack_a)->next->val)
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
		i++;
	}
	while (i > 0)
	{
		ps_rra(stack_a);
		i--;
	}
	return ;
}

void	insertion_sort_advanced(t_dlist **stack_a, t_dlist **stack_b)
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

// void	insertion_sort(t_dlist **stack_a, int len)
// {
// 	int	i;

//     i = 0;
//     len += 0;
// 	while (check_sorted(*stack_a, 1) == 0)
// 	{
//         while ((*stack_a)->next && (*stack_a)->val > (*stack_a)->next->val)
//         {
//             ps_sa(stack_a);
//             if (check_sorted(*stack_a, 1) == 1)
//                 break ;
//             ps_ra(stack_a);
//             i++;
//         }
//         if (check_sorted(*stack_a, 1) == 1)
//             break ;
//         ps_ra(stack_a);
//         i++;
// 	}
//     while (i > 0)
//     {
//         ps_rra(stack_a);
//         i--;
//     }
// 	return ;
// }