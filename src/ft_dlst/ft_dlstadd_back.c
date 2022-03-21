/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:55:19 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/27 18:03:24 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*dlst == NULL)
		*dlst = new;
	else
	{
		tmp = *dlst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->previous = tmp;
		tmp->next = new;
	}
}

/* Adds the element ’new’ at the end of the doubly linked list.
 */