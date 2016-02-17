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

int		pf_build_oint(t_printf *pf)
{
	uintmax_t		i;
	char			*tmp;

	pf->arg.length = (pf->in[pf->i] == 'O') ? l : pf->arg.length;
	i = pf_build_get_uint(pf);
	if (DEBUG)
		printf("\n%25s %6d %10s %jud\n", "pf_build_oint", pf->i, "value", i);
	if (i == 0 && pf->arg.ispreci && !pf->arg.preci && !pf->arg.diez)
		pf->join = ft_strnew(0);
	else if (!(pf->join = ft_uimaxtoa_base(i, "01234567")))
		return (1);
	pf->arg.diez = (i > 0) ? pf->arg.diez : 0;
	if (pf->arg.diez)
	{
		tmp = pf->join;
		pf->join = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	pf->arg.space = 0;
	pf->arg.more = 0;
	pf_build_itoa(pf);
	return (0);
}

int		pf_build_ptr(t_printf *pf)
{
	uintmax_t		i;

	pf->arg.length = l;
	i = pf_build_get_uint(pf);
	if (DEBUG)
		printf("\n%25s %6d %10s\n", "pf_build_ptr", pf->i, "NA");
	if (i == 0 && pf->arg.ispreci && !pf->arg.preci)
		pf->join = ft_strnew(0);
	else if (!(pf->join = ft_uimaxtoa_base(i, "0123456789abcdef")))
		return (1);
	pf->arg.diez2 = 2;
	pf->arg.space = 0;
	pf->arg.more = 0;
	if (pf->arg.zero && (pf->arg.zero2 = 1))
	{
		pf->arg.less = 1;
		pf->arg.zero = 0;
	}
	pf_build_itoa(pf);
	return (0);
}

int		pf_build_xint(t_printf *pf)
{
	uintmax_t		i;

	i = pf_build_get_uint(pf);
	if (DEBUG)
		printf("\n%25s %6d %10s %jud\n", "pf_build_xint", pf->i, "value", i);
	if (i == 0 && pf->arg.ispreci && !pf->arg.preci)
		pf->join = ft_strnew(0);
	else if (!(pf->join = ft_uimaxtoa_base(i, "0123456789abcdef")))
		return (1);
	pf->arg.toupper = (pf->in[pf->i] == 'X') ? 1 : pf->arg.toupper;
	pf->arg.diez = (i > 0) ? pf->arg.diez : 0;
	pf->arg.diez2 = pf->arg.diez * 2;
	pf->arg.space = 0;
	pf->arg.more = 0;
	pf_build_itoa(pf);
	return (0);
}

int					pf_build_int(t_printf *pf)
{
	intmax_t	i;

	pf->arg.length = (pf->in[pf->i] == 'D') ? l : pf->arg.length;
	i = pf_build_get_int(pf);
	if (DEBUG)
		printf("\n%25s %6d %10s %6jd\n", "pf_build_int", pf->i, "value", i);
	if (i == 0 && pf->arg.ispreci && !pf->arg.preci)
		pf->join = ft_strnew(0);
	else if (!(pf->join = ft_imaxtoa_base(i, "0123456789")))
		return (1);
	pf->arg.zero = (pf->arg.ispreci || pf->arg.less) ? 0 : pf->arg.zero;
	if (pf->arg.zero && i < 0 && (pf->arg.width > (int)ft_strlen(pf->join)))
		pf->arg.swapless = 1;
	if (i < 0 && pf->arg.preci >= (int)ft_strlen(pf->join) && pf->arg.preci++)
		pf->arg.swapless = 1;
	pf->arg.diez = 0;
	if (i < 0 && !(pf->arg.more = 0))
		pf->arg.space = 0;
	else if (pf->arg.more)
		pf->arg.space = 0;
	if (pf->arg.width > (int)ft_strlen(pf->join)
		&& (pf->arg.more || pf->arg.space))
		pf->arg.width--;
	pf_build_itoa(pf);
	return (0);
}

int		pf_build_uint(t_printf *pf)
{
	uintmax_t	i;

	pf->arg.length = (pf->in[pf->i] == 'U') ? l : pf->arg.length ;
	i = pf_build_get_uint(pf);
	if (DEBUG)
		printf("\n%25s %6d %10s %6ju\n", "pf_build_uint", pf->i, "value", i);
	if (i == 0 && pf->arg.ispreci && !pf->arg.preci)
		pf->join = ft_strnew(0);
	else if (!(pf->join = ft_uimaxtoa_base(i, "0123456789")))
		return (1);
	pf->arg.diez = 0;
	pf->arg.space = 0;
	pf->arg.more = 0;
	pf_build_itoa(pf);
	return (0);
}