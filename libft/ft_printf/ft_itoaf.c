/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:47:44 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 17:34:34 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(uintmax_t n)
{
	int		counter;

	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoaf(uintmax_t n)
{
	int		counter;
	char	*new;

	if (n == 0)
		return (ft_strdup("0"));
	counter = ft_counter(n);
	if (!(new = ft_strnew(counter)))
		return (NULL);
	while (n > 0)
	{
		new[counter - 1] = n % 10 + '0';
		n = n / 10;
		counter--;
	}
	return (new);
}
