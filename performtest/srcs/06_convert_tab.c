/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/30 22:47:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

static void	pt_set_handler06(void *handlers)
{
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
	static void *handlers = NULL;

	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		pt_set_handler06(handlers);
	}
	c += 1;
	*str += 1;
	*str -= 1;
}

void		pt_06_handle_escape(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_str(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_wstr(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_ptr(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_long(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_int(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_octal(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_unsigned(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_hex(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_char(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_wchar(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_binary(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_float(char **str)
{
	*str += 1;
	*str -= 1;
}
void		pt_06_handle_charswritten(char **str)
{
	*str += 1;
	*str -= 1;
}
