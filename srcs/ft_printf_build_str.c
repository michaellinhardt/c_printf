/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/17 05:47:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_build_wstring_preci(t_printf *pf, wchar_t const *ws)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (*ws && (i <= pf->arg.preci))
	{
		if (*ws <= 0x7F)
			i++;
		else if (*ws <= 0x7FF)
			i += 2;
		else if (*ws <= 0xFFFF)
			i += 3;
		else if (*ws <= 0x10FFFF)
			i += 4;
		if (*ws++)
			;
		last = i;
	}
	pf->arg.preci = last;
}

int			pf_build_wstring(t_printf *pf)
{
	wchar_t	*verif;
	char	*str;
	int		dofree;

	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_wstring", pf->i, "lettre", pf->in[pf->i]);
	dofree = 0;
	if (!(verif = (wchar_t *)va_arg(pf->ap, void *)) && (dofree = 1))
		verif = (wchar_t *)ft_strdup("(null)");
	str = ft_wstrtostr(verif);
	if (pf->arg.ispreci && pf->arg.preci)
		pf_build_wstring_preci(pf, verif);
	if (dofree)
		ft_memdel((void **)&verif);
	pf->join = (pf->arg.ispreci) ? ft_strsub(str, 0, pf->arg.preci) :
	ft_strdup(str);
	ft_strdel(&str);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf_build_format(pf);
	pf->valid = 1;
	return (0);
}

int			pf_build_string(t_printf *pf)
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
	pf_build_format(pf);
	pf->valid = 1;
	return (0);
}

int		pf_build_char(t_printf *pf)
{
	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_char", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strnew(1)) && (pf->ret = 1))
		return (0);
	if (!(pf->join[0] = (char)va_arg(pf->ap, void *)))
		pf->join[0] = (char)pf_build_nulchar(pf);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.ispreci = 0;
	pf->arg.preci = 0;
	pf_build_format(pf);
	pf->valid = 1;
	return (0);
}

int		pf_build_wchar(t_printf *pf)
{
	wchar_t wc;

	if (DEBUG)
		printf("\n%25s %6d %10s %6c\n", "pf_build_wchar", pf->i, "lettre", pf->in[pf->i]);
	if (!(wc = (wchar_t)va_arg(pf->ap, void *)))
		wc = (wchar_t)pf_build_nulchar(pf);
	if (!(pf->join = ft_wchartostr(wc)))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.ispreci = 0;
	pf->arg.preci = 0;
	pf_build_format(pf);
	pf->valid = 1;
	return (0);
}
