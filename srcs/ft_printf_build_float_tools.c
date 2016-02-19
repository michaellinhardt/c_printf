/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_float_tools.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 06:06:21 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/19 06:06:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	pf_build_float_get(t_printf *pf)
{
	long double	i;

	if (pf->arg.length == L && !(i = (long double)va_arg(pf->ap, long double)))
	{
		pf->j = 2;
		i = (long double)1.1;
	}
	else if (pf->arg.length != L && !(i = (long double)va_arg(pf->ap, double)))
	{
		pf->j = 2;
		i = (long double)1.1;
	}
	return (i);
}

int			pf_build_float_less(t_printf *pf)
{
	char		*tmp;

	if (pf->j == 1)
	{
		tmp = pf->join;
		if (!(pf->join = ft_strjoin("-", tmp)))
			return (1);
		ft_strdel(&tmp);
		pf->arg.more = 0;
		pf->arg.space = 0;
	}
	else
	{
		pf->join[0] = '0';
		pf->join[2] = '0';
	}
	return (0);
}

int			pf_build_float_right(t_printf *pf, long double i, int count)
{
	uintmax_t	right;
	int			next;

	pf->arg.preci = (!pf->arg.ispreci) ? 6 : pf->arg.preci;
	if (!(pf->join = ft_strnew(pf->arg.preci)))
		return (-1);
	count = -1;
	while (++count < pf->arg.preci && (i *= 10.0))
	{
		right = (uintmax_t)i;
		i = (long double)(i - (uintmax_t)i);
		pf->join[count] = right + '0' ;
	}
	if ((next = (uintmax_t)(i * 10)) > 4)
	{
		while (pf->join[--count])
			if ((pf->join[count] - '0') == 9 && (pf->join[count] = '0'))
				continue;
			else
			{
				pf->join[count] = ((pf->join[count] - '0') + 1) + '0' ;
				break;
			}
	}
	return ((count == -1) ? 1 : 0);
}
