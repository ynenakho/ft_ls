/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:00:06 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 17:52:50 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	va_list ap;
	int		result;
	t_arg	*flags;

	result = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			flags = create_struct(&fmt, &ap);
			result += ft_algo(flags, &ap);
		}
		else
		{
			ft_putchar(*fmt);
			result++;
			fmt++;
		}
	}
	va_end(ap);
	return (result);
}

t_arg		*create_struct(char **fmt, va_list *ap)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->width = 0;
	arg->precision = -1;
	arg->length = ft_strnew(0);
	arg->l = 0;
	ft_parse_flag(fmt, arg);
	ft_parse_width(fmt, arg, ap);
	ft_parse_precision(fmt, arg, ap);
	ft_parse_length(fmt, arg);
	ft_parse_sp(fmt, arg);
	return (arg);
}

void		del_structs(t_arg *arg)
{
	ft_strdel(&arg->length);
	ft_memdel((void**)&arg);
}
