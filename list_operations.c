/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operationc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:03:53 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/13 23:50:25 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_msg(char *filename)
{
	write(2, "ft_ls: ", 7);
	ft_putstr_fd(filename, 2);
	write(2, ": No such file or directory\n", 28);
}

void	ft_flstpush(t_flist **list, t_flist *new)
{
	t_flist *current;

	current = *list;
	if (!*list)
		*list = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_flist	*create_flist(char *path, char *filename)
{
	t_flist	*new;
	char	*tmp;

	new = (t_flist *)ft_memalloc(sizeof(t_flist));
	new->content.filename = ft_strnew(ft_strlen(filename));
	ft_memcpy(new->content.filename, filename, ft_strlen(filename));
	tmp = new->content.path;
	if (ft_strequ(path, "./") || ft_strequ(path, "/"))
		new->content.path = ft_strjoin(path, filename);
	else
		new->content.path = (path) ? ft_strmjoin(3, path, "/", filename) : NULL;
	if (tmp)
		ft_strdel(&tmp);
	if (lstat((new->content.path) ? new->content.path : new->content.filename,
				&new->content.info))
	{
		error_msg(filename);
		list_free(&new);
		return (NULL);
	}
	new->content.isfile = !S_ISDIR(new->content.info.st_mode);
	new->next = NULL;
	return (new);
}

t_flist	*make_main_list(t_all *all, char **argv)
{
	t_flist	*head;
	int		i;

	i = 0;
	head = NULL;
	if (all->argc == 0)
		ft_flstpush(&head, create_flist(NULL, "./"));
	while (all->argc-- > 0)
		ft_flstpush(&head, create_flist(NULL, (argv[i++])));
	return (head);
}
