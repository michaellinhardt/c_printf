/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_convert_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/01 12:48:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

static void	pt_set_handler06(void (**handlers)(char **))
{
	printf("set handlers\n");
	handlers['%'] = &pt_06_handle_escape;
	handlers['s'] = &pt_06_handle_str;
	handlers['S'] = &pt_06_handle_wstr;
	handlers['p'] = &pt_06_handle_ptr;
	handlers['d'] = &pt_06_handle_int;
	handlers['D'] = &pt_06_handle_long;
	handlers['i'] = &pt_06_handle_int;
	handlers['o'] = &pt_06_handle_octal;
	handlers['O'] = &pt_06_handle_long;
	handlers['u'] = &pt_06_handle_unsigned;
	handlers['U'] = &pt_06_handle_long;
	handlers['x'] = &pt_06_handle_hex;
	handlers['X'] = &pt_06_handle_hex;
	handlers['c'] = &pt_06_handle_char;
	handlers['C'] = &pt_06_handle_wchar;
	handlers['b'] = &pt_06_handle_binary;
	handlers['f'] = &pt_06_handle_float;
	handlers['n'] = &pt_06_handle_charswritten;
}

void		pt_get_handler06(char c, char **str)
{
	static void (*handlers[256])(char **) = {NULL};

	if (!handlers['%'])
		pt_set_handler06(handlers);
	if (handlers[(int)c])
		handlers[(int)c](str);
	else
		printf("bad specifier\n");
}

void		pt_06_handle_escape(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("modulo");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_str(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("str");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_wstr(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("wstr");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_ptr(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("ptr");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_long(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("long");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_int(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("int");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_octal(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("octal");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_unsigned(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("unsigned");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_hex(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("hex");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_char(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("char");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_wchar(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("wchar");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_binary(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("binary");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_float(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("float");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
void		pt_06_handle_charswritten(char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	t2 = ft_strdup("charswritten");
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	ft_strdel(&t2);
}
