/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstindex_lowest.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 12:32:34 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 14:27:26 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstindex_lowest(t_dlist **dlst, int value)
{
	int		lowest;

	lowest = 2147483647;
	while ((*dlst)->next)
	{
		if ((*dlst)->val == lowest && lowest != 2147483647)
			return (0);
		if ((*dlst)->val < lowest && (*dlst)->val >= value)
			lowest = (*dlst)->val;
		*dlst = (*dlst)->next;
	}
	if ((*dlst)->val == lowest && lowest != 2147483647)
		return (0);
	if ((*dlst)->val < lowest && (*dlst)->val >= value)
		lowest = (*dlst)->val;
	while ((*dlst)->val != lowest)
		*dlst = (*dlst)->previous;
	(*dlst)->val = value;
	while ((*dlst)->previous != NULL)
		*dlst = (*dlst)->previous;
	return (value + 1);
}
