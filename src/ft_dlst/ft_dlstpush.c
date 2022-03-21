/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstpush.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:50:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 15:06:09 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstpush(t_dlist **dlst1, t_dlist **dlst2)
{
	t_dlist	*tmp;

	tmp = (*dlst2)->next;
	if (!*dlst1 && !*dlst2)
		return ;
	else if (!*dlst1)
	{
		*dlst1 = ft_dlstnew((*dlst2)->val);
		(*dlst1)->next = NULL;
		tmp->previous = NULL;
		free(*dlst2);
		*dlst2 = tmp;
	}
	else
	{
		(*dlst1)->previous = *dlst2;
		(*dlst1)->previous->next = *dlst1;
		if (tmp)
			tmp->previous = NULL;
		(*dlst1)->previous->previous = NULL;
		*dlst1 = (*dlst1)->previous;
		*dlst2 = tmp;
	}
}

/*
	Push one element to the top of dlst1 from the top of dlst2.
*/
