/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:47:54 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		counter;
	size_t	little_len;

	if (!big)
		ft_strlen(big);
	if (0 == (little_len = ft_strlen((char *)little)))
		return ((char *)big);
	counter = 0;
	while (counter <= (int)(len - little_len) && *big)
	{
		if ((*big == *little) && (0 == ft_memcmp(big, little, little_len)))
			return (char *)big;
		big++;
		counter++;
	}
	return (NULL);
}
