/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:00:17 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/21 16:18:32 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		pf_build_double(t_printf *pf)
{
	long double	ld;

	ld = (pf->in[pf->i] == 'F' || pf->arg.length == L) ?
	(long double)va_arg(pf->ap, long double)
	: (long double)va_arg(pf->ap, double);
	pf->arg.preci = (!pf->arg.ispreci) ? 6 : pf->arg.preci;
	pf->join = ft_ldtoa(ld, pf->arg.preci);
	pf->arg.zero = (pf->arg.less) ? 0 : pf->arg.zero;
	pf->arg.diez = 0;
	if (ld < 0 && !(pf->arg.more = 0))
		pf->arg.space = 0;
	else if (pf->arg.more)
		pf->arg.space = 0;
	if (pf->arg.width > (int)ft_strlen(pf->join)
		&& (pf->arg.more || pf->arg.space))
		pf->arg.width--;
	pf_build_itoa(pf);
	return (0);
}
