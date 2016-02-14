/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:33:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_build_int(t_printf *pf)
{
	intmax_t	i;

	if (pf->arg.length == z)
		return (pf_build_uint(pf));
	i = va_arg(pf->ap, intmax_t);
	printf("\n%25s %6d %10s %6jd\n", "pf_build_int", pf->i, "value", i);
	if (!(pf->join = ft_imaxtoa_base(i, "0123456789")))
		return (1);
	pf->arg.diez = 0;
	if (i < 0 && !(pf->arg.more = 0))
		pf->arg.space = 0;
	else if (pf->arg.more)
		pf->arg.space = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}

int		pf_build_uint(t_printf *pf)
{
	uintmax_t	i;

	i = va_arg(pf->ap, uintmax_t);
	printf("\n%25s %6d %10s %6ju\n", "pf_build_uint", pf->i, "value", i);
	if (!(pf->join = ft_uimaxtoa_base(i, "0123456789")))
		return (1);
	pf->arg.diez = 0;
	if (pf->arg.more)
		pf->arg.space = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}
