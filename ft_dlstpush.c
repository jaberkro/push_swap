/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstpush.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:50:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 21:09:19 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_dlstpush(t_dlist **dlst1, t_dlist **dlst2)
{
    t_dlist *to;
    t_dlist *from;
    t_dlist *tmp;

    to = *dlst1;
    from = *dlst2;
    tmp = from->next;
    if (from->content)
    {
        to->previous = from;
        to->previous->next = to;
        tmp->previous = NULL;
        to->previous->previous = NULL;
        *dlst1 = to->previous;
        *dlst2 = tmp;
    }  
}
