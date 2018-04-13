/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:55:19 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 19:32:20 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_precision(t_arg *arg)
{
	char	*precision;

	if (arg->precision > (int)ft_strlen(arg->str))
	{
		precision = ft_strnew(arg->precision - ft_strlen(arg->str));
		ft_memset(precision, '0', arg->precision - ft_strlen(arg->str));
	}
	else
		precision = ft_strnew(0);
	return (precision);
}

static char	*ft_get_width(t_arg *arg)
{
	char	*width;
	int		x;

	x = (arg->flag.hash) ? 1 : 0;
	arg->l = ft_strlen(arg->str);
	if (arg->precision == -1 && (arg->width > arg->l + x) &&
			arg->flag.zero && !(arg->flag.left_j))
	{
		width = ft_strnew(arg->width - arg->l - x);
		ft_memset(width, '0', arg->width - arg->l - x);
	}
	else if (arg->width > arg->precision && arg->precision > arg->l + x)
	{
		width = ft_strnew(arg->width - arg->precision);
		ft_memset(width, ' ', arg->width - arg->precision);
	}
	else if (arg->width > (arg->l + x))
	{
		width = ft_strnew(arg->width - arg->l - x);
		ft_memset(width, ' ', arg->width - arg->l - x);
	}
	else
		width = ft_strnew(0);
	return (width);
}

static char	*ft_octal_helper(t_arg *arg, char *width, char *precision, char *h)
{
	char *result;
	char *tmp;

	tmp = arg->str;
	if (arg->precision != -1 && arg->precision != 0)
		arg->str = ft_strmjoin(2, precision, arg->str);
	else if (*width == '0')
		arg->str = ft_strmjoin(3, h, width, arg->str);
	else
		arg->str = ft_strjoin(h, arg->str);
	ft_strdel(&tmp);
	arg->l = ft_strlen(arg->str);
	if (arg->flag.left_j && *width == ' ' && (arg->width > arg->l))
		result = ft_strmjoin(2, arg->str, width);
	else if (*width == ' ' && !(arg->flag.left_j) && arg->width > arg->l)
		result = ft_strmjoin(2, width, arg->str);
	else
		result = ft_strdup(arg->str);
	return (result);
}

char		*ft_handle_octal(t_arg *arg, va_list *ap)
{
	char *result;
	char *precision;
	char *width;
	char *hash;

	convert_u(arg, ap);
	arg->str = ((arg->precision == 0) && (arg->val.uintm == 0)) ? ft_strnew(0) :
		ft_octal(arg->val.uintm);
	precision = ft_get_precision(arg);
	hash = (arg->flag.hash && ft_strcmp(arg->str, "0")) ? ft_strdup("0") :
		ft_strnew(0);
	width = ft_get_width(arg);
	result = ft_octal_helper(arg, width, precision, hash);
	arg->l = ft_strlen(result);
	ft_strdel(&arg->str);
	ft_strdel(&precision);
	ft_strdel(&width);
	ft_strdel(&hash);
	return (result);
}
