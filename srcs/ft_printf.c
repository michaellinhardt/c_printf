/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/03 01:59:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_printf	*pf;

	if (!(pf = pf_singleton(0)) || !(pf->join = ft_strnew(0)))
		return (pf_return(-1));
	va_start(pf->ap, format);
	if (pf_parse(format))
		return (pf_return(-1));



	ft_putstr(pf->join);
	va_end(pf->ap);
	return (pf_return(ft_strlen(pf->join)));
}

int		pf_return(int ret)
{
	t_printf	*pf;

	if ((pf = pf_singleton(0)))
		ft_strdel(&pf->join);
	return (ret);
}
