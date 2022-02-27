/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstswap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:32:05 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/27 18:20:48 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstswap(t_dlist **dlst)
{
	t_dlist	*tmp;

	tmp = (*dlst)->next;
	if ((*dlst)->content && tmp->content)
	{
		(*dlst)->next = tmp->next;
		(*dlst)->next->previous = *dlst;
		(*dlst)->previous = tmp;
		(*dlst)->previous->next = *dlst;
		*dlst = tmp;
	}
}

/* 
	Swap two upper elements of a doubly linked list
*/
