/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:41:00 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_printf
{
	int				i;
	int				start;
	char			*join;
	int				ret;
}					t_printf;

// FICHIER PRINTF.C
int			ft_printf(const char *restrict format, ...);
t_printf	*pf_singleton(int last);

// FICHIER JOIN.C
int			pf_join(int method, const char *restrict format);

// FICHIER PARSE.C
int		pf_parse(const char *restrict format, ...);

#include <stdio.h>
#endif
