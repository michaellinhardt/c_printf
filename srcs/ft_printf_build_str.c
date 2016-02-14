/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/14 11:22:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
