/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:28:13 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/14 01:36:59 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <stdbool.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>

extern int		g_optint;

typedef struct	s_flags
{
	bool	l;
	bool	rec;
	bool	r;
	bool	a;
	bool	t;
}				t_flags;

typedef struct	s_info
{
	bool		isfile;
	char		*filename;
	char		*path;
	char		*link_path;
	struct stat info;
}				t_info;

typedef struct	s_flist
{
	t_info	content;
	void	*next;
}				t_flist;

typedef struct	s_all
{
	int		first;
	int		flag;
	bool	multargs;
	int		argc;
	t_flags flags;
}				t_all;

typedef struct	s_sort
{
	t_flist	*newend;
	t_flist *newhead;
	t_flist *tmp;
	t_flist *prev;
	t_flist *tail;
}				t_sort;

typedef int		(*t_funcs)(t_flist *, t_flist *);

int				ft_getopt(char **argv, char *optstr);
void			quicksort(t_flist **headref, t_flags flags);
t_flist			*make_main_list(t_all *all, char **argv);
void			handle_main_list(t_all *all, t_flist **args);
void			ft_flstpush(t_flist **list, t_flist *res);
t_flist			*create_flist(char *path, char *filename);
void			handle_dirs(t_all *all, t_flist **dirs);
void			print_list(t_all *all, t_flist *list);
int				ft_gettotal(t_flist *list);
char			ft_getmodeacl(char *path);
t_funcs			get_sort(t_flags flags);
int				lex_sort(t_flist *one, t_flist *two);
char			*get_linkpath(t_info *file);
void			list_del(t_flist **root);
void			list_free(t_flist **train);
t_flist			*pop_elem(t_flist **root);
char			*ft_getgrgid(gid_t st_gid);
char			*ft_getpwuid(uid_t st_uid);

#endif
