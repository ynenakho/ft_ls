/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:49:18 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/09 17:49:21 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flist *make_files_list(t_flist **args, t_flist **dirs)
{
  t_flist *tmp;
  t_flist *res;

  res = NULL;
  tmp = NULL;
  while ((tmp = pop_elem(args)))
  {
    tmp->next = NULL;
    ft_flstpush((tmp->content.isfile) ? &res : dirs, tmp);

  //  list_del(&tmp);
  }
  return (res);
}

t_flist *read_dir(t_all *all, char *path)
{
  t_flist *list;
  DIR *ds;
  struct dirent *dir;

  list = NULL;
  ds = opendir(path);
	if (!ds)
	{
		ft_printf("ft_ls: %s: Permission denied\n", path);
		return (NULL);
	}
  while ((dir = readdir(ds)) != NULL)
  {
    if (!all->flags.a && ((dir->d_name[0] == '.')))
      continue ;
    ft_flstpush(&list, create_flist(path, dir->d_name));
  }
  closedir(ds);
  return (list);
}

void handle_dirs_helper(t_all *all, t_flist **list)
{
	t_flist *files;
	t_flist *dirs;

	files = NULL;
	dirs = NULL;
	if (all->flags.l)
		ft_printf("total %d\n", ft_gettotal(*list));
	quicksort(&*list, all->flags);
	print_list(all, *list);
	if (all->flags.rec)
	{
		files = make_files_list(&*list, &dirs);
		quicksort(&dirs, all->flags);
		ft_memdel((void**)&*list);
		ft_memdel((void**)&files);
		handle_dirs(all, &dirs);
	}
}

void handle_dirs(t_all *all, t_flist **dirs)
{
  t_flist *tmp;
  char *path;
  t_flist *list;


  tmp = NULL;
	path = NULL;
	if (!*dirs)
		return ;
  while ((tmp = pop_elem(dirs)))
  {
    tmp->next = NULL;
		path = (tmp->content.path) ? tmp->content.path : tmp->content.filename;
		if  (ft_strequ(tmp->content.filename, ".") || ft_strequ(tmp->content.filename, ".."))
		{
      list_free(&tmp);
			//ft_memdel((void **)&tmp);
			continue ;
		}
		if (all->flag++)
			ft_putchar('\n');
		if ((all->multargs || all->flags.rec) && all->first++)
    	ft_printf("%s:\n", path);
    list = read_dir(all, path);
		handle_dirs_helper(all, &list);
		//ft_memdel((void **)&tmp);
    list_del(&tmp);

  }
}

void handle_main_list(t_all *all, t_flist **args)
{
  t_flist *files;
  t_flist *dirs;

	if (!*args)
		return;
  dirs = NULL;
  if (!all->multargs && (*args)->content.isfile)
  {
    print_list(all, *args);
	  list_del(&*args);
    return ;
  }
  files = make_files_list(args, &dirs);

  quicksort(&files, all->flags);
  quicksort(&dirs, all->flags);
  if (files)
	{
    print_list(all, files);
		list_del(&files);
	}
  if (dirs)
  {
    handle_dirs(all, &dirs);
  	list_del(&dirs);
  }

}
