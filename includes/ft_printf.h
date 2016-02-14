/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/14 09:58:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// # include <wchar.h>
// # include <locale.h>

# define DEBUG 0

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
	int				valid;
	int				i;
	int				j;
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

// FICHIER BUILD_STR.C
int			pf_build_string(t_printf *pf);
int			pf_build_char(t_printf *pf);

// FICHIER BUILD_INT.C
int			pf_build_int(t_printf *pf);
int			pf_build_uint(t_printf *pf);
int			pf_build_oint(t_printf *pf);
int			pf_build_xint(t_printf *pf);
int			pf_build_ptr(t_printf *pf);

// FICHIER BUILD_TOOLS_INT
uintmax_t	pf_build_get_uint(t_printf *pf);
intmax_t	pf_build_get_int(t_printf *pf);
void		pf_build_itoa(t_printf *pf);

// FICHIER BUILD_TOOLS
int			pf_build_invalid(t_printf *pf);
int			pf_build_nulchar(t_printf *pf);
int			pf_build_modulo(t_printf *pf);

// FICHIER BUILD_FORMAT.C
void		pf_build_format(t_printf *pf);

// FICHIER DEBUG.C
void		pf_print_flags(t_printf *pf);

#include <stdio.h>
#endif
