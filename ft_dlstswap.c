/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstswap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:32:05 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 21:00:27 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_dlstswap(t_dlist **dlst)
{
    t_dlist *tmp;
    t_dlist *pos;

    pos = *dlst;
    tmp = pos->next;
    if (pos->content && tmp->content)
    {
        pos->next = tmp->next;
        pos->next->previous = pos;
        pos->previous = tmp;
        pos->previous->next = pos;
        *dlst = tmp;
    }
}
