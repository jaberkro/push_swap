/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstindex_lowest.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 12:32:34 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 13:30:04 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstindex_lowest(t_dlist **dlst, int value)
{
	int		lowest;

	lowest = 2147483647;
	while ((*dlst)->next)
	{
		if ((*dlst)->content == lowest && lowest != 2147483647)
			return (0);
		if ((*dlst)->content < lowest && (*dlst)->content >= value)
			lowest = (*dlst)->content;
		*dlst = (*dlst)->next;
	}
	if ((*dlst)->content == lowest && lowest != 2147483647)
		return (0);
	if ((*dlst)->content < lowest && (*dlst)->content >= value)
		lowest = (*dlst)->content;
	while ((*dlst)->content != lowest)
		*dlst = (*dlst)->previous;
	(*dlst)->content = value;
	while ((*dlst)->previous != NULL)
		*dlst = (*dlst)->previous;
	return (value + 1);
}
