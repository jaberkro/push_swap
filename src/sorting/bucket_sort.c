/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 15:04:58 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 15:50:40 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bucket_one_four(t_dlist **stack_a, t_dlist **stack_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		// ft_printf("i:%d\n", i);
		// ft_printf("a: ");
		// print_dlist(*stack_a);
		// ft_printf("b: ");
		// print_dlist(*stack_b);
		while (((*stack_a)->val > 0 && (*stack_a)->val <= len / 5) || \
		((*stack_a)->val > len / 5 * 3 && (*stack_a)->val <= len / 5 * 4))
		{
			if ((*stack_a)->val <= len / 5)
			{
				ps_pb(stack_b, stack_a);
				// if ((*stack_b)->val < ft_dlstlast(*stack_a)->val)
				// {
				// 	ps_rrb(stack_b);
				// 	ps_sb(stack_b);
				// 	ps_rb(stack_b);
				// }
				ps_rb(stack_b);
			}
			else
			{
				ps_pb(stack_b, stack_a);
				// if ((*stack_b)->next && (*stack_b)->val < (*stack_b)->next->val)
				// 	ps_sb(stack_b);
			}
			i++;
			if (i >= len)
				break ;
		}
		ps_ra(stack_a);
		i++;
	}
	return ;
}

static void	bucket_two_three(t_dlist **stack_a, t_dlist **stack_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		// ft_printf("i:%d\n", i);
		// ft_printf("a: ");
		// print_dlist(*stack_a);
		// ft_printf("b: ");
		// print_dlist(*stack_b);
		while ((*stack_a)->val > len / 5 && (*stack_a)->val <= len / 5 * 3)
		{
			if ((*stack_a)->val <= len / 5 * 2)
			{
				ps_pb(stack_b, stack_a);
				// if ((*stack_b)->val < ft_dlstlast(*stack_a)->val)
				// {
				// 	ps_rrb(stack_b);
				// 	ps_sb(stack_b);
				// 	ps_rb(stack_b);
				// }
				ps_rb(stack_b);
			}
			else
			{
				ps_pb(stack_b, stack_a);
				// if ((*stack_b)->next && (*stack_b)->val < (*stack_b)->next->val)
				// 	ps_sb(stack_b);
			}
			i++;
			if (i >= len)
				break ;
		}
		ps_ra(stack_a);
		i++;
	}
	return ;
}

void	bucket_sort(t_dlist **stack_a)
{
	int		len;
	//int		i;
	t_dlist	*stack_b = NULL;

	len = ft_dlstlen(*stack_a);
	//amount = len / 5;
	bucket_two_three(stack_a, &stack_b, len);
	bucket_one_four(stack_a, &stack_b, len);
	// i = 0;
	// while (i < amount)
	// {
	// 	bucket_next_two(stack_a, &stack_b, len, i);
	// 	i += 5;
	// }
	//f//t_printf("a: ");
	//print_dlist(*stack_a);
	//ft_printf("b: ");
	//print_dlist(stack_b);
	//ft_printf("b: ");
	//print_dlist(stack_b);
	//insertion_sort(stack_a, len / 5);
	//ft_printf("a: ");
	bubble_sort(stack_a, 1);
	//print_dlist(*stack_a);
	while (stack_b && stack_b->val)
	{
		// i = 0;
		// while (i < len / 5)
		// {
			//ps_pa(stack_a, &stack_b);
			//print_dlist(*stack_a);
			//insertion_sort(stack_a, len);
			insertion_sort_advanced(stack_a, &stack_b);
		// 	i++;
		// }
		//bubble_sort(stack_a, 1);
		//print_dlist(*stack_a);
		// while (i + 1 > 0)
		// {
		// 	ps_ra(stack_a);
		// 	i--;
		// }
		//print_dlist(*stack_a);
	}
}


/*

t_dlist	*quick_sort(t_dlist **stack_a, int start, int end)
{
	t_dlist	*stack_b;
	int		pivot;

	stack_b = NULL;
	pivot = (end - start) / 2 + start;
	ft_printf("*%d*\n", pivot);
	
	return (*stack_a);
}
*/
/*
	QUICK_SORT

	1) choose a pivot
	2) find first from left that is lower than pivot, save in low
	3) find first from right that is higher than pivot, save in high
	4) if low is more right than high, than pivot should be at this place and
	 break. Else: swap low and high 
	5) repeat until pivot is at it's location
	6) if you found pivot, now sort left of it and after that the right side of it.

*/
