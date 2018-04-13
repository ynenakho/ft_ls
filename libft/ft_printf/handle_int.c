/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:03:16 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 18:34:37 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_sign(intmax_t n, t_arg *arg)
{
	if (n < 0)
	{
		arg->val.intm = arg->val.intm * (-1);
		arg->sign = ft_strdup("-");
	}
	else if (arg->flag.force_sign)
		arg->sign = ft_strdup("+");
	else if (arg->flag.space)
		arg->sign = ft_strdup(" ");
	else
	{
		arg->sign = ft_strnew(0);
		return (0);
	}
	return (1);
}

static char	*ft_get_precision(t_arg *arg)
{
	char *precision;

	if (arg->l < arg->precision)
	{
		precision = ft_strnew(arg->precision - arg->l);
		ft_memset(precision, '0', arg->precision - arg->l);
	}
	else
		precision = ft_strnew(0);
	arg->l += ft_strlen(precision);
	return (precision);
}

static char	*ft_get_width(t_arg *arg, int x)
{
	char *width;

	if (arg->l + x < arg->width && arg->flag.zero && arg->precision == -1
			&& !(arg->flag.left_j))
	{
		width = ft_strnew(arg->width - arg->l - x);
		ft_memset(width, '0', arg->width - arg->l - x);
	}
	else if (arg->l + x < arg->width)
	{
		width = ft_strnew(arg->width - arg->l - x);
		ft_memset(width, ' ', arg->width - arg->l - x);
	}
	else
		width = ft_strnew(0);
	return (width);
}

char		*ft_handle_int(t_arg *arg, va_list *ap)
{
	char	*result;
	int		sign;
	char	*width;
	char	*precision;
	char	*val;

	convert(arg, ap);
	sign = get_sign(arg->val.intm, arg);
	val = ((arg->precision == 0) && (arg->val.intm == 0)) ? ft_strnew(0) :
		ft_itoaf(arg->val.intm);
	arg->l = ft_strlen(val);
	precision = ft_get_precision(arg);
	width = ft_get_width(arg, sign);
	if (arg->flag.left_j)
		result = ft_strmjoin(4, arg->sign, precision, val, width);
	else if (*width == ' ')
		result = ft_strmjoin(4, width, arg->sign, precision, val);
	else
		result = ft_strmjoin(4, arg->sign, width, precision, val);
	arg->l = ft_strlen(result);
	ft_strdel(&arg->sign);
	ft_strdel(&val);
	ft_strdel(&width);
	ft_strdel(&precision);
	return (result);
}
