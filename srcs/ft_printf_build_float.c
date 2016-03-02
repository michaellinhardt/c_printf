/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 01:12:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/02 14:42:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_build_float_g(t_printf *pf)
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

static int		pf_build_float_e2(t_printf *pf)
{
	char		*tmp;
	char		*itoa;
	int			j;

	if (!(tmp = ft_strnew(ft_strlen(pf->join) + 4)))
		return (1);
	j = -1;
	while (pf->join[++j])
		tmp[j] = pf->join[j];
	tmp[j++] = pf->in[pf->i];
	tmp[j++] = pf->e;
	if (!(itoa = ft_itoa(pf->k)))
		return (1);
	if (pf->k < 10 && ((tmp[j++] = '0') || 1))
		tmp[j++] = *itoa;
	else if ((tmp[j++] = *itoa++) || 1)
		tmp[j++] = *itoa++;
	ft_strdel(&pf->join);
	pf->join = tmp;
	ft_strdel(&itoa);
	return (0);
}

static long double	pf_build_float_e1(t_printf *pf, long double i)
{
	if (i >= 10 && ((pf->k++) || 1) && (pf->e = '+'))
		return (pf_build_float_e1(pf, (i / 10)));
	if ((int)i == 0 && (pf->e = '-') && ((pf->k++) || 1))
		return (pf_build_float_e1(pf, (i * 10)));
	return (i);
}

int					pf_build_float(t_printf *pf)
{
	long double	i;

	i = pf_build_float_get(pf);
	i *= (i < 0 && (pf->j = 1)) ? -1 : 1;
	if ((pf->e = '+') && (pf->in[pf->i] == 'e' || pf->in[pf->i] == 'E'))
		i = pf_build_float_e1(pf, i);
	if (pf_build_float_normal(pf, i))
		return (1);
	if (pf->in[pf->i] == 'g' || pf->in[pf->i] == 'G')
		pf_build_float_g(pf);
	if ((pf->in[pf->i] == 'e' || pf->in[pf->i] == 'E') && pf_build_float_e2(pf))
			return (1);
	pf_build_itoa(pf);
	return (0);
}
