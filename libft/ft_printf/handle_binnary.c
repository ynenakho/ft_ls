/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binnary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 23:58:49 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 19:08:44 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_binary(unsigned char octet)
{
	int		i;
	char	*res;
	int		counter;

	res = ft_strnew(9);
	counter = 0;
	i = 128;
	while (i)
	{
		if (octet & i)
			res[counter++] = '1';
		else
			res[counter++] = '0';
		if (i == 16)
			res[counter++] = ' ';
		i >>= 1;
	}
	return (res);
}

char		*ft_handle_binary(t_arg *arg, va_list *ap)
{
	char	*result;

	convert_u(arg, ap);
	result = ft_get_binary(arg->val.uintm);
	arg->l = ft_strlen(result);
	return (result);
}
