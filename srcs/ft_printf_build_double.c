/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:00:17 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/21 18:17:32 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	pf_build_float_short(t_printf *pf)
{
	int		i;

	if (ft_strchr(pf->join, '.'))
	{
		i = (int)ft_strlen(pf->join);
		while (--i > -1 && pf->join[i] == '0')
			pf->join[i] = '\0';
		pf->join[i] = (pf->join[i] == '.') ? '\0' : pf->join[i];
	}
}

int			pf_build_exp(t_printf *pf)
{
	long double	ld;
	int			e;
	char		c;

	ld = (pf->arg.length == L) ?
	(long double)va_arg(pf->ap, long double)
	: (long double)va_arg(pf->ap, double);
	pf->arg.preci = (!pf->arg.ispreci) ? 6 : pf->arg.preci;
	c = '+';
	e = 0;
	while ((ld < -9.9 || ld > 9.9) && ++e)
		ld /= 10;
	while (ld > -1 && ld < 1 && ++e && (c = '-'))
		ld *= 10;
	printf("%Lf\n", ld);

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
	pf->valid = 1;
	pf_build_format(pf);
	return (0);
}

int			pf_build_float(t_printf *pf)
{
	long double	ld;

	ld = (pf->arg.length == L) ?
	(long double)va_arg(pf->ap, long double)
	: (long double)va_arg(pf->ap, double);
	pf->arg.preci = (!pf->arg.ispreci) ? 6 : pf->arg.preci;
	pf->join = ft_ldtoa(ld, pf->arg.preci);
	if (pf->in[pf->i] == 'g' || pf->in[pf->i] == 'G')
		pf_build_float_short(pf);
	pf->arg.zero = (pf->arg.less) ? 0 : pf->arg.zero;
	pf->arg.diez = 0;
	if (ld < 0 && !(pf->arg.more = 0))
		pf->arg.space = 0;
	else if (pf->arg.more)
		pf->arg.space = 0;
	if (pf->arg.width > (int)ft_strlen(pf->join)
		&& (pf->arg.more || pf->arg.space))
		pf->arg.width--;
	pf->valid = 1;
	pf_build_format(pf);
	return (0);
}
