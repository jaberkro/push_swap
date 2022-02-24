/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:29:09 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 18:20:15 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	t_dlist *tmp;

	tmp = *dlst;
	new->next = *dlst;
	tmp->previous = new;
	*dlst = new;
}
