/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:07:50 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/14 01:35:34 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_flist	*gettail(t_flist *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

static t_flist	*partition(t_flist *head, t_flist *end,
		t_sort *s, t_funcs func)
{
	s->prev = NULL;
	s->tail = end;
	while (head != end)
	{
		if (func(head, end))
		{
			s->newhead = !(s->newhead) ? head : s->newhead;
			s->prev = head;
			head = head->next;
		}
		else
		{
			if (s->prev)
				s->prev->next = head->next;
			s->tmp = head->next;
			head->next = NULL;
			s->tail->next = head;
			s->tail = head;
			head = s->tmp;
		}
	}
	(s->newhead) = !(s->newhead) ? end : s->newhead;
	(s->newend) = s->tail;
	return (end);
}

static t_flist	*quicksortrecur(t_flist *head, t_flist *end, t_funcs func)
{
	t_flist	*pivot;
	t_sort	s;
	t_flist	*tmp;

	ft_bzero(&s, sizeof(t_sort));
	if (!head || head == end)
		return (head);
	pivot = partition(head, end, &s, func);
	if (s.newhead != pivot)
	{
		tmp = s.newhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		s.newhead = quicksortrecur(s.newhead, tmp, func);
		tmp = gettail(s.newhead);
		tmp->next = pivot;
	}
	pivot->next = quicksortrecur(pivot->next, s.newend, func);
	return (s.newhead);
}

void			quicksort(t_flist **headref, t_flags flags)
{
	(*headref) = quicksortrecur(*headref, gettail(*headref), get_sort(flags));
	return ;
}
