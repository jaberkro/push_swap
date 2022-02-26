/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:29:09 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/26 16:20:11 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	new->next = *dlst;
	(*dlst)->previous = new;
	*dlst = new;
}
