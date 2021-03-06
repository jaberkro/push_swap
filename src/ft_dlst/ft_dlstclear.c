/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstclear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 18:37:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 17:15:04 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstclear(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	while ((*dlst)->previous)
		*dlst = (*dlst)->previous;
	while (*dlst)
	{
		tmp = *dlst;
		*dlst = (*dlst)->next;
		free(tmp);
	}
}
