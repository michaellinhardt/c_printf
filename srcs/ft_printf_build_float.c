/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 01:12:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/26 01:08:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_build_float_short(t_printf *pf)
{
	int		i;
	int		j;

	i = ft_strlen(pf->join);
	j = (i - 1);
	while (pf->join[--i])
	{
		if (pf->join[i] == '0')
			pf->join[i] = '\0';
		else
			break;
	}
	if (pf->join[i] == '.')
		pf->join[i] = '\0';
	pf->arg.preci = 0;
}

static int			pf_build_float_normal(t_printf *pf, long double i)
{
	char		*left;
	char		*right;
	int			verif;

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
	return (0);
}

static long double	pf_build_float_e(t_printf *pf, long double i, int step)
{
	char		*tmp;
	char		*itoa;
	int			j;

	if (step == 1)
	{
		if (i >= 10 && ((pf->k++) || 1) && (pf->e = '+'))
			return (pf_build_float_e(pf, (i / 10), 1));
		if ((int)i == 0 && (pf->e = '-') && ((pf->k++) || 1))
			return (pf_build_float_e(pf, (i * 10), 1));
		return (i);
	}
	else
	{
		if (!(tmp = ft_strnew(ft_strlen(pf->join) + 4)))
			return ((long double)(pf->ret = 1));
		j = -1;
		while (pf->join[++j])
			tmp[j] = pf->join[j];
		tmp[j++] = pf->in[pf->i];
		tmp[j++] = pf->e;
		if (!(itoa = ft_itoa(pf->k)))
			return ((long double)(pf->ret = 1));
		if (pf->k < 10)
		{
			tmp[j++] = '0';
			tmp[j++] = *itoa;
		}
		else
		{
			tmp[j++] = *itoa++;
			tmp[j++] = *itoa++;
		}
		ft_strdel(&pf->join);
		pf->join = tmp;
		ft_strdel(&itoa);
	}
	return (i);
}

int					pf_build_float(t_printf *pf)
{
	long double	i;

	i = pf_build_float_get(pf);
	i *= (i < 0 && (pf->j = 1)) ? -1 : 1;
	if (pf->in[pf->i] == 'e' || pf->in[pf->i] == 'E')
		i = pf_build_float_e(pf, i, 1);
	if (pf_build_float_normal(pf, i))
		return (1);
	if (pf->in[pf->i] == 'g' || pf->in[pf->i] == 'G')
		pf_build_float_short(pf);
	if (pf->in[pf->i] == 'e' || pf->in[pf->i] == 'E')
	{
		pf_build_float_e(pf, i, 2);
		if (pf->ret == 1)
			return (1);
	}
	pf_build_itoa(pf);
	return (0);
}
