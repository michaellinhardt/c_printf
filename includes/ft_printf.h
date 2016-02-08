/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/08 01:30:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_arg
{
	int				modulo;
	int				diez;
	int				zero;
	int				more;
	int				less;
	int				space;
	int				width;
	int				preci;
	int				col;
	char			*d_color;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

typedef struct		s_printf
{
	int				i;
	int				start;
	char			*join;
	char			*in;
	char			*out;
	int				ret;
	va_list			ap;
	t_arg			arg;
}					t_printf;

// FICHIER PRINTF.C
int			ft_printf(const char *restrict format, ...);
int			pf_return(t_printf *pf, int ret);

// FICHIER JOIN.C
int			pf_join(t_printf *pf, int src);

// FICHIER PARSE.C
int			pf_parse(t_printf *pf);

// FICHIER SINGLETON.C
t_printf	*pf_singleton(int last);

#include <stdio.h>
#endif
