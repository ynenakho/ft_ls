/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:06:43 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 17:53:48 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hex(uintmax_t nb)
{
	char	new[20];
	char	*str;
	int		i;
	int		counter;

	if (nb == 0)
		return (ft_strdup("0"));
	counter = 0;
	str = ft_strnew(20);
	ft_bzero(str, 20);
	while (nb > 0)
	{
		i = nb % 16;
		if (i < 10)
			new[counter++] = i + 48;
		else
			new[counter++] = i + 87;
		nb = nb / 16;
	}
	i = 0;
	while (counter)
	{
		str[i++] = new[--counter];
	}
	return (str);
}

char		*ft_octal(uintmax_t nb)
{
	char	new[20];
	char	*str;
	int		i;
	int		counter;

	if (nb == 0)
		return (ft_strdup("0"));
	counter = 0;
	str = ft_strnew(20);
	ft_bzero(str, 20);
	while (nb > 0)
	{
		i = nb % 8;
		new[counter++] = i + 48;
		nb = nb / 8;
	}
	i = 0;
	while (counter)
	{
		str[i++] = new[--counter];
	}
	return (str);
}
