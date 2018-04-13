/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:48 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/03 20:08:50 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wstr_helper(char *res, t_arg *arg)
{
	char	*value_to_print;
	char	*prefix_postfix;
	char	*tmp;

	arg->val.str = res;
	value_to_print = get_precision_str(arg);
	prefix_postfix = get_width_str(arg);
	tmp = res;
	if (arg->flag.left_j)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&value_to_print);
	ft_memdel((void **)&prefix_postfix);
	arg->l = ft_strlen(res);
	return (res);
}
