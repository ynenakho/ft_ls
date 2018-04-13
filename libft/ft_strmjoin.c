/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:13:19 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/24 20:14:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strmjoin(int num, ...)
{
	va_list ap;
	char	*res;
	char	*tmp;
	char	*arg;

	res = ft_strnew(0);
	va_start(ap, num);
	while (num--)
	{
		arg = va_arg(ap, char *);
		tmp = res;
		res = ft_strjoin(tmp, arg);
		ft_memdel((void **)&tmp);
	}
	va_end(ap);
	return (res);
}
