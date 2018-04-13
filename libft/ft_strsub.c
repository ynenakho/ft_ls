/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 02:46:30 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*new;
	char	*newptr;

	if (!s1)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	newptr = new;
	while (s1[start] && len--)
		*newptr++ = s1[start++];
	*newptr = '\0';
	return (new);
}
