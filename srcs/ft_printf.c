/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/14 08:20:54 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_print(t_printf *pf)
{
	pf->ret = ft_strlen(pf->out);
	pf->j = -1;
	while (pf->nulchar[++pf->j] > -1)
		pf->out[(pf->nulchar[pf->j])] = '\0';
	write(1, pf->out, pf->ret);
}

static int		pf_return(t_printf *pf, int ret)
{
	ft_strdel(&pf->in);
	ft_strdel(&pf->join);
	ft_strdel(&pf->out);
	return (ret);
}

int			ft_printf(const char *restrict format, ...)
{
	t_printf		pf;

	if (!format)
		return (-1);
	ft_bzero((void **)&pf, sizeof(t_printf));
	if (!(pf.out = ft_strnew(0)))
		return (pf_return(&pf, -1));
	pf.join = NULL;
	pf.in = ft_strdup(format);
	va_start(pf.ap, format);
	pf.nulchar[0] = -1;
	if (pf_parse(&pf))
		return (pf_return(&pf, -1));
	pf_print(&pf);
	va_end(pf.ap);
	return (pf_return(&pf, pf.ret));
}

void		pf_print_flags(t_printf *pf)
{
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "modulo", pf->arg.modulo);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "diez", pf->arg.diez);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "more", pf->arg.more);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "space", pf->arg.space);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "zero", pf->arg.zero);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "less", pf->arg.less);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "width", pf->arg.width);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "preci", pf->arg.preci);
	printf("%25s %6d %10s %6d\n", "pf_print_flags", pf->i, "col", pf->arg.col);
}
