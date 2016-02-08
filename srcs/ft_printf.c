/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/08 01:20:18 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_printf	*pf;

	if (!(pf = pf_singleton(0)) || !(pf->out = ft_strnew(0)))
		return (pf_return(pf, -1));
	pf->join = NULL;
	va_start(pf->ap, format);
	if (pf_parse(pf, format))
		return (pf_return(pf, -1));
	ft_putstr(pf->out);
	// printf("out: %s\n", pf->out);
	va_end(pf->ap);
	return (pf_return(pf, ft_strlen(pf->out)));
}

int		pf_return(t_printf *pf, int ret)
{
	ft_strdel(&pf->join);
	ft_strdel(&pf->out);
	return (ret);
}
