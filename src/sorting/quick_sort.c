/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 15:04:58 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 15:50:40 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
