/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:35:38 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/13 23:54:56 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			lex_sort(t_flist *one, t_flist *two)
{
	return (strcmp(one->content.filename, two->content.filename) < 0);
}

static int	rev_lex_sort(t_flist *one, t_flist *two)
{
	return (ft_strcmp(one->content.filename, two->content.filename) > 0);
}

static int	time_sort(t_flist *one, t_flist *two)
{
	if (one->content.info.st_mtimespec.tv_sec ==
			two->content.info.st_mtimespec.tv_sec)
	{
		if (one->content.info.st_mtimespec.tv_nsec ==
				two->content.info.st_mtimespec.tv_nsec)
			return (lex_sort(one, two));
		else
			return (one->content.info.st_mtimespec.tv_nsec >
					two->content.info.st_mtimespec.tv_nsec);
	}
	return (one->content.info.st_mtimespec.tv_sec >
			two->content.info.st_mtimespec.tv_sec);
}

static int	rev_time_sort(t_flist *one, t_flist *two)
{
	if (one->content.info.st_mtimespec.tv_sec ==
			two->content.info.st_mtimespec.tv_sec)
	{
		if (one->content.info.st_mtimespec.tv_nsec ==
				two->content.info.st_mtimespec.tv_nsec)
			return (lex_sort(two, one));
		else
			return (one->content.info.st_mtimespec.tv_nsec <
					two->content.info.st_mtimespec.tv_nsec);
	}
	return (one->content.info.st_mtimespec.tv_sec <
			two->content.info.st_mtimespec.tv_sec);
}

t_funcs		get_sort(t_flags flags)
{
	if (flags.r && flags.t)
		return (&rev_time_sort);
	if (flags.r)
		return (&rev_lex_sort);
	if (flags.t)
		return (&time_sort);
	return (&lex_sort);
}
