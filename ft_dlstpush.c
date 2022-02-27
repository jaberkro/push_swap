/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstpush.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:50:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/27 18:10:36 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstpush(t_dlist **dlst1, t_dlist **dlst2)
{
	t_dlist	*tmp;

	tmp = (*dlst2)->next;
	if ((*dlst2)->content)
	{
		(*dlst1)->previous = *dlst2;
		(*dlst1)->previous->next = *dlst1;
		tmp->previous = NULL;
		(*dlst1)->previous->previous = NULL;
		*dlst1 = (*dlst1)->previous;
		*dlst2 = tmp;
	}
}

/*
	Push one element to the top of dlst1 from the top of dlst2.
*/
