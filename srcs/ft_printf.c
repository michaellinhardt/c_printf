/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/01 15:42:56 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, format);
	pf_init(&pf);
	while (format[pf.i++])
		;
	// if (pf.end = pf.i && (pf.i - pf.start) > 0)
	// 	pf_join(&pf)
	va_end(ap);
	return (0);
}

void	pf_init(t_printf *pf)
{
	ft_bzero(pf, sizeof(pf));
	if (!pf->join && !(pf->join = ))
}

/*
""
"aa"
"%s"
*/
