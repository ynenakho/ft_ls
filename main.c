/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:42:31 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/14 00:18:44 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**check_flags(char **argv, int argc, t_all *all)
{
	int x;

	while ((x = ft_getopt(argv, "lRrat")) != -1)
	{
		if (x == 'l')
			all->flags.l = true;
		if (x == 'R')
			all->flags.rec = true;
		if (x == 'r')
			all->flags.r = true;
		if (x == 'a')
			all->flags.a = true;
		if (x == 't')
			all->flags.t = true;
	}
	argv += g_optint;
	argc -= g_optint;
	all->multargs = (argc <= 1) ? false : true;
	all->argc = argc;
	return (argv);
}

int			main(int argc, char **argv)
{
	t_all	all;
	t_flist	*args;

	ft_bzero(&all, sizeof(t_all));
	argv = check_flags(argv, argc, &all);
	args = make_main_list(&all, argv);
	handle_main_list(&all, &args);
	list_del(&args);
	return (0);
}
