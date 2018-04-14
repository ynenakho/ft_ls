/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:12:06 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/13 23:56:23 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_free(t_flist **train)
{
	t_flist	*ptr;

	ptr = *train;
	ft_strdel(&(ptr->content.link_path));
	ft_strdel(&(ptr->content.path));
	ft_strdel(&(ptr->content.filename));
	ft_memdel((void **)&ptr);
	*train = NULL;
}

void	list_del(t_flist **root)
{
	t_flist		*current;
	t_flist		*next;

	current = *root;
	while (current)
	{
		next = current->next;
		list_free(&current);
		current = next;
	}
	*root = NULL;
}

char	*get_linkpath(t_info *file)
{
	ssize_t	len;

	file->link_path = ft_strnew(1024);
	if ((len = readlink((file->path) ? (file->path) : file->filename,
					file->link_path, 1023)) != -1)
		file->link_path[len] = '\0';
	return (file->link_path);
}

char	ft_getmodeacl(char *path)
{
	int		xattrs;
	acl_t	acl;

	xattrs = (int)listxattr(path, NULL, 1, XATTR_NOFOLLOW);
	if (xattrs > 0)
		return ('@');
	else
	{
		acl = acl_get_file(path, ACL_TYPE_EXTENDED);
		return ((acl != NULL) ? '+' : '\0');
	}
}

int		ft_gettotal(t_flist *list)
{
	t_flist	*current;
	int		total;

	total = 0;
	current = list;
	while (current)
	{
		total += current->content.info.st_blocks;
		current = current->next;
	}
	return (total);
}
