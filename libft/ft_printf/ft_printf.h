/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:42:32 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 18:28:24 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"
# include <wchar.h>

typedef union
{
	char		chr;
	char		*str;
	intmax_t	intm;
	uintmax_t	uintm;
	void		*ptr;
}				t_val;

typedef	struct	s_flag
{
	int			left_j;
	int			force_sign;
	int			space;
	int			hash;
	int			zero;
}				t_flag;

typedef struct	s_arg
{
	char		*str;
	char		*sign;
	int			width;
	int			precision;
	char		*length;
	char		sp;
	int			l;
	t_flag		flag;
	t_val		val;
}				t_arg;

typedef char*	(*t_func)(t_arg*, va_list*);

char			*ft_handle_binary(t_arg *arg, va_list *ap);
t_func			get_func(char c);
void			del_structs(t_arg *arg);
char			*get_width_str(t_arg *args);
char			*get_precision_str(t_arg *args);
char			*ft_wstr_helper(char *res, t_arg *arg);
char			*ft_handle_wstr(t_arg *arg, va_list *ap);
char			*ft_handle_wchar(t_arg *arg, va_list *ap);
char			*ft_handle_addr(t_arg *arg, va_list *ap);
char			*ft_handle_uint(t_arg *arg, va_list *ap);
char			*ft_handle_char(t_arg *arg, va_list *ap);
char			*ft_handle_octal(t_arg *arg, va_list *ap);
char			*ft_handle_hex(t_arg *arg, va_list *ap);
char			*ft_handle_str(t_arg *arg, va_list *ap);
char			*ft_itoaf(uintmax_t n);
void			convert_u(t_arg *arg, va_list *ap);
void			convert(t_arg *arg, va_list *ap);
char			*ft_handle_int(t_arg *arg, va_list *ap);
char			*ft_octal(uintmax_t nb);
char			*ft_hex(uintmax_t nb);
int				ft_printf(char *fmt, ...) __attribute__((format(printf,1,2)));
t_arg			*create_struct(char **fmt, va_list *ap);
void			ft_parse_flag(char **fmt, t_arg *arg);
void			ft_parse_width(char **fmt, t_arg *arg, va_list *ap);
void			ft_parse_precision(char **fmt, t_arg *arg, va_list *ap);
void			ft_parse_length(char **fmt, t_arg *arg);
void			ft_parse_sp(char **fmt, t_arg *arg);
int				ft_algo(t_arg *arg, va_list *ap);
int				ft_wcharlen(wchar_t wc);

#endif
