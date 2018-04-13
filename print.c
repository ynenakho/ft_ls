/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 04:57:22 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/11 04:57:23 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *ft_gettime(long sectime)
{
  char *ret;
  char *fulltime;
  time_t now;

  ret = ft_strnew(12);
  time(&now);
  fulltime = ctime(&sectime);
  if (ABS(sectime - now) > 15770000)
  {
    ft_memcpy(ret, fulltime + 4, 7);
    ft_memcpy(ret + 7, fulltime + 19 , 5);
  }
  else
    ft_memcpy(ret, fulltime + 4, 12);
  return (ret);
}

static char		ft_modehelp(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

char *ft_getmode(t_flist *list)
{
  char *fmode;

  //ft_bzero(fmode, 12);
  fmode = ft_strnew(11);
  *fmode++ = ft_modehelp(list->content.info.st_mode);
  *fmode++ = (list->content.info.st_mode & S_IRUSR) ? 'r' : '-';
  *fmode++ = (list->content.info.st_mode & S_IWUSR) ? 'w' : '-';
  *fmode++ = (list->content.info.st_mode & S_IXUSR) ? 'x' : '-';
  *fmode++ = (list->content.info.st_mode & S_IRGRP) ? 'r' : '-';
  *fmode++ = (list->content.info.st_mode & S_IWGRP) ? 'w' : '-';
  *fmode++ = (list->content.info.st_mode & S_IXGRP) ? 'x' : '-';
  *fmode++ = (list->content.info.st_mode & S_IROTH) ? 'r' : '-';
  *fmode++ = (list->content.info.st_mode & S_IWOTH) ? 'w' : '-';
  if (list->content.info.st_mode & S_ISVTX)
    *fmode++ = 't';
  else
    *fmode++ = (list->content.info.st_mode & S_IXOTH) ? 'x' : '-';
//  *fmode++ = ft_getmodeacl((list->content.path) ? list->content.path : list->content.filename);

  return (fmode - 11);
}

static void print_list_2(t_all *all, t_flist *list)
{
  if (all->flags.l)
  {
    ft_printf("%s ", ft_getmode(list));
    ft_printf("%d ", list->content.info.st_nlink);
    ft_printf("%s ", ft_getpwuid(list->content.info.st_uid));
    ft_printf("%s ", ft_getgrgid(list->content.info.st_gid));
    if (S_ISCHR(list->content.info.st_mode) || S_ISBLK(list->content.info.st_mode))
			ft_printf("%i, %i ", major(list->content.info.st_rdev),
        minor(list->content.info.st_rdev));
		else
     ft_printf("%lli ", list->content.info.st_size);
    ft_printf("%s ", ft_gettime(list->content.info.st_mtimespec.tv_sec));
  }
}

void print_list(t_all *all, t_flist *list)
{
  while (list)
  {
    print_list_2(all, list);
    ft_printf("%s", list->content.filename);
    if (S_ISLNK(list->content.info.st_mode) && all->flags.l)
			ft_printf(" -> %s\n", get_linkpath(&list->content));
		else
			ft_printf("\n");
    list = list->next;
		all->first++;
    all->flag++;
  }

}
