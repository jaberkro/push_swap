/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort_decimals.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 12:21:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 13:58:49 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	present(t_dlist *stack, int decimal, int tofind)
{
	while (stack)
	{
		if ((stack->val) / decimal % 10 == tofind)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	find_closest(t_dlist *stack, int dec, int i)
{
	int		forward;
	int		backward;
	t_dlist	*tmp;

	forward = 0;
	backward = 1;
	tmp = ft_dlstlast(stack);
	if (present(stack, dec, i) == 0)
		return (1000);
	while (tmp && (tmp->val / dec % 10 != i))
	{
		tmp = tmp->previous;
		backward++;
	}
	while (stack && (stack->val / dec % 10 != i))
	{
		stack = stack->next;
		forward++;
	}
	if (forward < backward)
		return (forward);
	return (backward);
}

static void	sort_descend(t_dlist **stack_a, t_dlist **stack_b, int dec, int i)
{
	int	j;
	int	len;
	int	rotate_count;

	rotate_count = 0;
	len = ft_dlstlen(*stack_a);
	j = 0;
	while (j < len)
	{
		if (present(*stack_a, dec, i) == 0 && rotate_count > 0)
		{
			rotate_back(stack_a, rotate_count, ft_dlstlen(*stack_a), 0);
			break ;
		}
		if (*stack_a && (((*stack_a)->val) / dec) % 10 == i)
			ps_pb(stack_b, stack_a);
		else if (*stack_a)
		{
			ps_ra(stack_a);
			rotate_count++;
		}
		j++;
	}
}

static void	sort_ascend(t_dlist **stack_a, t_dlist **stack_b, int dec, int i)
{
	int	j;
	int	len;
	int	rotate_count;

	rotate_count = 0;
	len = ft_dlstlen(*stack_b);
	j = 0;
	while (j < len)
	{
		if (present(*stack_b, dec, i) == 0 && rotate_count > 0)
		{
			rotate_back(stack_b, rotate_count, ft_dlstlen(*stack_b), 1);
			break ;
		}
		if (*stack_b && (((*stack_b)->val) / dec) % 10 == i)
			ps_pa(stack_a, stack_b);
		else if (*stack_b)
		{
			ps_rb(stack_b);
			rotate_count++;
		}
		j++;
	}
}

void	radix_sort(t_dlist **stack_a, int total)
{
	int		i;
	int		decimal;
	t_dlist	*stack_b;

	decimal = 1;
	stack_b = NULL;
	while (decimal <= total)
	{
		if (*stack_a && check_sorted(*stack_a, 1) == 1)
			return ;
		i = 0;
		while (i < 10)
		{
			sort_descend(stack_a, &stack_b, decimal, i);
			i++;
		}
		decimal *= 10;
		i = 9;
		while (i >= 0)
		{
			sort_ascend(stack_a, &stack_b, decimal, i);
			i--;
		}
		decimal *= 10;
	}
}
