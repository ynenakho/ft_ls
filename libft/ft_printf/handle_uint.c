/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:31:49 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 18:25:45 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_precision(t_arg *arg)
{
	char	*precision;

	if (arg->l < arg->precision)
	{
		precision = ft_strnew(arg->precision - arg->l);
		ft_memset(precision, '0', arg->precision - arg->l);
	}
	else
		precision = ft_strnew(0);
	return (precision);
}

static char	*ft_get_width(t_arg *arg)
{
	char	*width;

	if (arg->l < arg->width && arg->flag.zero && arg->precision == -1)
	{
		width = ft_strnew(arg->width - arg->l);
		ft_memset(width, '0', arg->width - arg->l);
	}
	else if (arg->l < arg->width)
	{
		width = ft_strnew(arg->width - arg->l);
		ft_memset(width, ' ', arg->width - arg->l);
	}
	else
		width = ft_strnew(0);
	return (width);
}

char		*ft_handle_uint(t_arg *arg, va_list *ap)
{
	char	*result;
	char	*precision;
	char	*width;
	char	*val;

	convert_u(arg, ap);
	val = ((arg->precision == 0) && (arg->val.uintm == 0)) ? ft_strnew(0) :
		ft_itoaf(arg->val.uintm);
	arg->l = ft_strlen(val);
	precision = ft_get_precision(arg);
	arg->l += ft_strlen(precision);
	width = ft_get_width(arg);
	if (arg->flag.left_j)
		result = ft_strmjoin(3, precision, val, width);
	else
		result = ft_strmjoin(3, width, precision, val);
	arg->l = ft_strlen(result);
	ft_strdel(&val);
	ft_strdel(&width);
	ft_strdel(&precision);
	return (result);
}
