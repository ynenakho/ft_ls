/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:07:50 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/04 15:07:56 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static t_flist *gettail(t_flist *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return (cur);
}

static t_flist *partition(t_flist *head, t_flist *end,
                       t_flist **newhead, t_flist **newend, t_funcs func)
{
    t_flist *pivot;
    t_flist *prev;
    t_flist *cur;
    t_flist *tail;

    prev = NULL;
    pivot = end;
    tail = pivot;
    cur = head;
    while (cur != pivot)
    {
        if (func(cur, pivot))
        {
            if ((*newhead) == NULL)
                (*newhead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            t_flist *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newhead) == NULL)
        (*newhead) = pivot;
    (*newend) = tail;

    return (pivot);
}

static t_flist *quicksortrecur(t_flist *head, t_flist *end, t_funcs func)
{
    t_flist *pivot;
    t_flist *newend;
    t_flist *newhead;

    if (!head || head == end)
        return (head);
    newhead = NULL;
    newend = NULL;
    pivot = partition(head, end, &newhead, &newend, func);
    if (newhead != pivot)
    {
        t_flist *tmp = newhead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newhead = quicksortrecur(newhead, tmp, func);
        tmp = gettail(newhead);
        tmp->next =  pivot;
    }
    pivot->next = quicksortrecur(pivot->next, newend, func);
    return (newhead);
}

void quicksort(t_flist **headref, t_flags flags)
{
    (*headref) = quicksortrecur(*headref, gettail(*headref), get_sort(flags));
    return;
}
