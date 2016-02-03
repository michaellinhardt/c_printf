/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/03 05:43:06 by mlinhard         ###   ########.fr       */
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
	int				diez : 1;
	int				zero : 1;
	int				more : 1;
	int				less : 1;
	int				space : 1;
	int				wid : 1;
	int				pre : 1;
	int				col : 1;
	unsigned int	width;
	unsigned int	precision;
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
	int				ret;
	va_list			ap;
	t_arg			arg;
}					t_printf;

// FICHIER PRINTF.C
int			ft_printf(const char *restrict format, ...);
int			pf_return(int ret);

// FICHIER JOIN.C
int			pf_join(int method, const char *restrict format);

// FICHIER PARSE.C
int			pf_parse(const char *restrict format);

// FICHIER SINGLETON.C
t_printf	*pf_singleton(int last);

#include <stdio.h>
#endif
