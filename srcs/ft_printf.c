/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:41:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_printf	*pf;

	va_start(ap, format);
	if (!(pf = pf_singleton(0)) || !(pf->join = ft_strnew(0))
	|| pf_parse(format))
		return (-1);



	pf->ret = ft_strlen(pf->join);
	ft_putstr(pf->join);
	ft_strdel(&pf->join);
	va_end(ap);
	return (pf->ret);
}
