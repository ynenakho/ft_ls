/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:28:15 by ynenakho          #+#    #+#             */
/*   Updated: 2018/04/13 15:28:18 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flist		*pop_elem(t_flist **root)
{
	t_flist		*result;

	if (!(*root))
		return (NULL);
	result = *root;
	*root = (*root)->next;
	return (result);
}

char *ft_getgrgid(gid_t st_gid)
{
  struct group *gid;

  gid = getgrgid(st_gid);
  return(gid->gr_name);
}

char *ft_getpwuid(uid_t st_uid)
{
  struct passwd *uid;

  uid = getpwuid(st_uid);
  return(uid->pw_name);
}
