/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:44:09 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:07 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		length;
	char	*new;

	length = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (*src != '\0')
	{
		*new = *src;
		src++;
		new++;
	}
	*new = '\0';
	return (new - length);
}
