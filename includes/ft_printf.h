/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/02 17:56:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct		s_arg
{
	int				modulo;
	int				diez;
	int				diez2;
	int				more;
	int				space;
	int				zero;
	int				zero2;
	int				less;
	int				swapless;
	int				width;
	int				preci;
	int				ispreci;
	int				col;
	int				toupper;
	char			*d_color;
	enum {
		none,
		L,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

typedef struct		s_printf
{
	int				valid;
	int				i;
	int				j;
	int				k;
	char			e;
	int				start;
	char			*join;
	char			*in;
	char			*out;
	int				ret;
	int				nulchar[512];
	va_list			ap;
	t_arg			arg;
}					t_printf;

// FICHIER PRINTF.C
int			ft_printf(const char *restrict format, ...);

// FICHIER JOIN.C
int			pf_join(t_printf *pf, int src);

// FICHIER PARSE.C
int			pf_parse(t_printf *pf);

// FICHIER PARSE_OPTION.C
int			pf_parse_flag(t_printf *pf);
int			pf_parse_length(t_printf *pf);
int			pf_parse_preci(t_printf *pf);
int			pf_parse_width(t_printf *pf);

// FICHIER BUILD_FORMAT.C
void		pf_build_format(t_printf *pf);

// FICHIER BUILD_STR.C
int			pf_build_string(t_printf *pf);
int			pf_build_char(t_printf *pf);
int			pf_build_wstring(t_printf *pf);
int			pf_build_wchar(t_printf *pf);

// FICHIER BUILD_INT.C
int			pf_build_int(t_printf *pf);
int			pf_build_uint(t_printf *pf);

// FICHIER BUILD_INT_BASE.C
int			pf_build_oint(t_printf *pf);
int			pf_build_xint(t_printf *pf);
int			pf_build_ptr(t_printf *pf);
int			pf_build_binary(t_printf *pf);

// FICHIER BUILD_INT_TOOLS
uintmax_t	pf_build_get_uint(t_printf *pf);
intmax_t	pf_build_get_int(t_printf *pf);
void		pf_build_itoa(t_printf *pf);

// FICHIER BUILD_FLOAT.C
int			pf_build_float(t_printf *pf);

// FICHIER BUILD_FLOAT_TOOLS.C
long double	pf_build_float_get(t_printf *pf);
int			pf_build_float_less(t_printf *pf);
int			pf_build_float_right(t_printf *pf, long double i, int count);

// FICHIER BUILD_TOOLS
int			pf_build_invalid(t_printf *pf);
int			pf_build_nulchar(t_printf *pf);
int			pf_build_modulo(t_printf *pf);

// FICHIER BUILD_COLOR
int			pf_build_color(t_printf *pf);

// FICHIER BUILD_ARRAY
int			pf_build_array(t_printf *pf);

#include <stdio.h>
#endif
