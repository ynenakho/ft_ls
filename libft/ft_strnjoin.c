/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:50:10 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 02:17:31 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int size)
{
	int		s1_length;
	int		s2_length;
	int		min;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new = ft_strnew(s1_length + s2_length);
	min = (s2_length < size) ? s2_length : size;
	if (!new)
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2 && size--)
		*new++ = *s2++;
	*new = '\0';
	return (new - s1_length - min);
}
