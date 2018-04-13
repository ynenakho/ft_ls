/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:50:24 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 19:50:45 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			ft_algo(t_arg *arg, va_list *ap)
{
	char	*value;
	t_func	f;
	int		res;

	f = get_func(arg->sp);
	if (f)
		value = f(arg, ap);
	else if (arg->width != 0)
	{
		arg->l = arg->width;
		value = ft_strnew(arg->width);
		ft_memset(value, ' ', arg->width);
		res = (arg->flag.left_j) ? 0 : arg->width - 1;
		ft_memset(value + res, arg->sp, 1);
	}
	else
	{
		arg->l = 1;
		value = ft_strnew(1);
		ft_memset(value, arg->sp, 1);
	}
	res = write(1, value, arg->l);
	ft_memdel((void **)&value);
	del_structs(arg);
	return (res);
}

static void	init_funcs(t_func *funcs)
{
	funcs['x'] = &ft_handle_hex;
	funcs['X'] = &ft_handle_hex;
	funcs['s'] = &ft_handle_str;
	funcs['S'] = &ft_handle_wstr;
	funcs['i'] = &ft_handle_int;
	funcs['d'] = &ft_handle_int;
	funcs['D'] = &ft_handle_int;
	funcs['o'] = &ft_handle_octal;
	funcs['O'] = &ft_handle_octal;
	funcs['%'] = &ft_handle_char;
	funcs['c'] = &ft_handle_char;
	funcs['C'] = &ft_handle_char;
	funcs['p'] = &ft_handle_addr;
	funcs['b'] = &ft_handle_binary;
	funcs['U'] = &ft_handle_uint;
	funcs['u'] = &ft_handle_uint;
}

t_func		get_func(char c)
{
	static t_func	*funcs;

	if (!funcs)
	{
		funcs = ft_memalloc(sizeof(*funcs) * 256);
		if (funcs)
			init_funcs(funcs);
	}
	return (funcs[(int)c]);
}
