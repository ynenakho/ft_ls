/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:19:48 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 19:06:53 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(char **fmt, t_arg *arg)
{
	(*fmt)++;
	arg->flag.left_j = 0;
	arg->flag.force_sign = 0;
	arg->flag.space = 0;
	arg->flag.hash = 0;
	arg->flag.zero = 0;
	while (**fmt == ' ' || **fmt == '#' || **fmt == '+' || **fmt == '-' ||
			**fmt == '0')
	{
		if (**fmt == '-')
			arg->flag.left_j = 1;
		if (**fmt == '+')
			arg->flag.force_sign = 1;
		if (**fmt == ' ')
			arg->flag.space = 1;
		if (**fmt == '#')
			arg->flag.hash = 1;
		if (**fmt == '0')
			arg->flag.zero = 1;
		(*fmt)++;
	}
}

void	ft_parse_width(char **fmt, t_arg *arg, va_list *ap)
{
	char *tmp;

	tmp = *fmt;
	while (ft_isdigit(*tmp))
		tmp++;
	if (**fmt == '*')
	{
		arg->width = va_arg(*ap, int);
		if (arg->width < 0)
		{
			arg->width *= -1;
			arg->flag.left_j = 1;
		}
		(*fmt)++;
	}
	else
	{
		arg->width = ft_atoi(*fmt);
		(*fmt) = tmp;
	}
}

void	ft_parse_precision(char **fmt, t_arg *arg, va_list *ap)
{
	char *tmp;

	if (**fmt == '.')
	{
		(*fmt)++;
		tmp = *fmt;
		while (ft_isdigit(*tmp))
			tmp++;
		if (**fmt == '*')
		{
			arg->precision = va_arg(*ap, int);
			if (arg->precision < 0)
			{
				arg->precision *= -1;
				arg->flag.left_j = 1;
			}
			(*fmt)++;
		}
		else
		{
			arg->precision = ft_atoi(*fmt);
			(*fmt) = tmp;
		}
	}
}

void	ft_parse_length(char **fmt, t_arg *arg)
{
	char *tmp;
	char *tmpp;

	tmpp = arg->length;
	if ((**fmt == 'h') || (**fmt == 'l'))
	{
		arg->length = ft_strnjoin(arg->length, *fmt, 1);
		if ((*(++(*fmt)) == 'h' && !ft_strcmp(arg->length, "h")) ||
				(**fmt == 'l' && !ft_strcmp(arg->length, "l")))
		{
			tmp = arg->length;
			arg->length = ft_strnjoin(arg->length, *fmt, 1);
			ft_strdel(&tmp);
		}
		else
			(*fmt)--;
	}
	else if (**fmt == 'j')
		arg->length = ft_strnjoin(arg->length, *fmt, 1);
	else if (**fmt == 'z')
		arg->length = ft_strnjoin(arg->length, *fmt, 1);
	else
		return ;
	ft_strdel(&tmpp);
	(*fmt)++;
}

void	ft_parse_sp(char **fmt, t_arg *arg)
{
	char *tmp;

	arg->sp = **fmt;
	(*fmt)++;
	if (arg->sp == 's' && !ft_strcmp(arg->length, "l"))
		arg->sp = 'S';
	if (arg->sp == 'c' && !ft_strcmp(arg->length, "l"))
		arg->sp = 'C';
	if ((arg->sp == 'U' || arg->sp == 'O' || arg->sp == 'D') &&
			ft_strcmp(arg->length, "l"))
	{
		tmp = arg->length;
		arg->length = ft_strdup("l");
		ft_strdel(&tmp);
	}
}
