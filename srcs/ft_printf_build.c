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

int		pf_build_invalid(t_printf *pf)
{
	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_invalid", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strnew(0)))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	if (pf->arg.width)
		pf->arg.width--;
	if (pf_build_format(pf))
		return (1);
	return (0);
}

int		pf_build_modulo(t_printf *pf)
{
	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_modulo", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strdup("%")))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.preci = 0;
	if (pf_build_format(pf))
		return (1);
	pf->valid = 1;
	return (0);
}

int		pf_build_string(t_printf *pf)
{
	char	*verif;
	int		dofree;

	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_string", pf->i, "lettre", pf->in[pf->i]);
	dofree = 0;
	if (!(verif = (char *)va_arg(pf->ap, void *)) && (dofree = 1))
		verif = ft_strdup("(null)");
	pf->join = (pf->arg.ispreci) ? ft_strsub(verif, 0, pf->arg.preci) :
	ft_strdup(verif);
	if (dofree)
		ft_strdel(&verif);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	if (pf_build_format(pf))
		return (1);
	pf->valid = 1;
	return (0);
}

int		pf_build_oint(t_printf *pf)
{
	uintmax_t		i;
	char			*tmp;

	i = va_arg(pf->ap, uintmax_t);
	if (DEBUG)
		printf("\n%25s %6d %10s %jud\n", "pf_build_oint", pf->i, "value", i);
	if (!(pf->join = ft_uimaxtoa_base(i, "01234567")))
		return (1);
	if (pf->arg.diez)
	{
		tmp = pf->join;
		pf->join = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	pf->arg.space = 0;
	pf->arg.more = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}

int		pf_build_ptr(t_printf *pf)
{
	uintmax_t		i;

	i = (uintmax_t)va_arg(pf->ap, void *);
	if (DEBUG)
		printf("\n%25s %6d %10s\n", "pf_build_ptr", pf->i, "NA");
	if (!(pf->join = ft_uimaxtoa_base(i, "0123456789abcdef")))
		return (1);
	pf->arg.diez2 = 1;
	pf->arg.space = 0;
	pf->arg.more = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}

int		pf_build_xint(t_printf *pf)
{
	uintmax_t		i;

	i = va_arg(pf->ap, uintmax_t);
	if (DEBUG)
		printf("\n%25s %6d %10s %jud\n", "pf_build_xint", pf->i, "value", i);
	if (!(pf->join = ft_uimaxtoa_base(i, "0123456789abcdef")))
		return (1);
	pf->arg.diez2 = pf->arg.diez;
	pf->arg.space = 0;
	pf->arg.more = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}

int		pf_build_xint2(t_printf *pf)
{
	uintmax_t		i;

	i = va_arg(pf->ap, uintmax_t);
	if (DEBUG)
		printf("\n%25s %6d %10s %6ju\n", "pf_build_xint2", pf->i, "value", i);
	if (!(pf->join = ft_strtoupper(ft_uimaxtoa_base(i, "0123456789abcdef"))))
		return (1);
	pf->arg.diez2 = pf->arg.diez;
	pf->arg.space = 0;
	pf->arg.more = 0;
	if (pf_build_itoa(pf))
		return (1);
	return (0);
}

int		pf_build_itoa(t_printf *pf)
{
	int		i;
	int		len;
	char	*tmp;

	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_itoa", pf->i, "lettre", pf->in[pf->i]);
	if (pf->arg.preci && pf->arg.preci > (int)ft_strlen(pf->join))
	{
		if (!(tmp = ft_strnew(pf->arg.preci)))
			return (1);
		i = -1;
		pf->j = -1;
		len = (int)ft_strlen(pf->join);
		while (++i < pf->arg.preci)
			tmp[i] = ((pf->arg.preci - i) > len) ? '0' : pf->join[++pf->j];
		ft_strdel(&pf->join);
		pf->join = tmp;
	}
	if (pf_build_format(pf))
		return (1);
	pf->valid = 1;
	return (0);
}

int		pf_build_char(t_printf *pf)
{
	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_char", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strnew(1)))
		return (1);
	pf->join[0] = (char)va_arg(pf->ap, int);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.preci = 0;
	if (pf_build_format(pf))
		return (1);
	pf->valid = 1;
	return (0);
}
