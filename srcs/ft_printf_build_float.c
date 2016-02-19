/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 01:12:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/19 06:08:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					pf_build_float(t_printf *pf)
{
	long double	i;
	char		*left;
	char		*right;
	int			verif;

	i = pf_build_float_get(pf);
	i *= (i < 0 && (pf->j = 1)) ? -1 : 1;
	if ((verif = pf_build_float_right(pf, i - (uintmax_t)i, -1)) == -1)
		return (1);
	if (!(right = ft_imaxtoa_base((intmax_t)i + verif, "0123456789")))
		return (1);
	if (!(left = ft_strjoin(right, ".")))
		return (1);
	ft_strdel(&right);
	right = pf->join;
	if (!(pf->join = ft_strjoin(left, right)))
		return (1);
	if (pf->j && pf_build_float_less(pf))
		return (1);
	pf->arg.width -= (pf->arg.more || pf->arg.space) ? 1 : 0;
	ft_strdel(&left);
	ft_strdel(&right);
	pf_build_itoa(pf);
	return (0);
}
