/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_smallest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 13:52:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 16:13:01 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_highest_lowest(t_dlist *stack, int *highest, int *lowest)
{
	while (stack && stack->val)
	{
		if (stack->val > *highest)
			*highest = stack->val;
		if (stack->val < *lowest)
			*lowest = stack->val;
		stack = stack->next;
	}
}

static void	three_sort_a(t_dlist **stack_a)
{
	int		low;
	int		up;
	t_dlist	*tmp;

	up = 0;
	low = 2147483647;
	find_highest_lowest(*stack_a, &up, &low);
	tmp = *stack_a;
	if (tmp->val == up)
	{
		ps_ra(stack_a);
		if (check_sorted(*stack_a, 1) == 0)
			ps_sa(stack_a);
	}
	else if ((tmp->val == low) && (tmp->next->val == up))
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	else if (tmp->next->val == low)
		ps_sa(stack_a);
	else if (check_sorted(*stack_a, 1) == 0)
		ps_rra(stack_a);
	return ;
}

static void	three_sort_b(t_dlist **stack_b)
{
	int		low;
	int		up;
	t_dlist	*tmp;

	up = 0;
	low = 2147483647;
	find_highest_lowest(*stack_b, &up, &low);
	tmp = *stack_b;
	if (tmp->val == low)
	{
		ps_rb(stack_b);
		if (check_sorted(*stack_b, 0) == 0)
			ps_sb(stack_b);
	}
	else if ((tmp->val == up) && (tmp->next->val == low))
	{
		ps_sb(stack_b);
		ps_rb(stack_b);
	}
	else if (tmp->next->val == up)
		ps_sb(stack_b);
	else if (check_sorted(*stack_b, 0) == 0)
		ps_rrb(stack_b);
	return ;
}

static void	six_sort(t_dlist **stack_a, t_dlist **stack_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while ((*stack_a)->val < len - 2)
		{
			ps_pb(stack_b, stack_a);
			i++;
		}
		if (i >= len)
			break ;
		ps_ra(stack_a);
		i++;
	}
	three_sort_a(stack_a);
	if (len == 5 && check_sorted(*stack_b, 0) == 0)
		ps_sb(stack_b);
	else if (len == 6)
		three_sort_b(stack_b);
	while (*stack_b)
		ps_pa(stack_a, stack_b);
	return ;
}

void	smallest_sort(t_dlist **stack_a)
{
	int		len;
	t_dlist	*stack_b;

	stack_b = NULL;
	len = ft_dlstlen(*stack_a);
	if (check_sorted(*stack_a, 1) == 1)
		return ;
	else if (len == 2)
		ps_ra(stack_a);
	else if (len == 3)
		three_sort_a(stack_a);
	else
		six_sort(stack_a, &stack_b, len);
	return ;
}
