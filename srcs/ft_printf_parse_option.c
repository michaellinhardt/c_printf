/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 02:19:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/14 11:49:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parse_flag(t_printf *pf)
{
	if (DEBUG)
		printf("%25s %6d %10s %6c\n", "pf_parse_flag", pf->i, "lettre", pf->in[pf->i]);
	if ((pf->in[pf->i] == '#') && (pf->arg.diez = 1))
		return (1);
	if ((pf->in[pf->i] == '0') && (pf->arg.zero = 1))
		return (1);
	if ((pf->in[pf->i] == '+') && (pf->arg.more = 1))
		return (1);
	if ((pf->in[pf->i] == '-') && (pf->arg.less = 1))
		return (1);
	if ((pf->in[pf->i] == ' ') && (pf->arg.space = 1))
		return (1);
	// if ((pf->in[pf->i] == '{') && (pf->arg.col = 1))
	// 	return (1);
	return (1);
}

int		pf_parse_length(t_printf *pf)
{
	if (DEBUG)
		printf("%25s %6d %10s %6c\n", "pf_parse_length", pf->i, "lettre", pf->in[pf->i]);
	if (pf->in[(pf->i + 1)] && (pf->in[(pf->i + 1)] == 'h')
	&& (pf->in[pf->i] == 'h') && (pf->arg.length = hh) && pf->i++)
		return (1);
	if ((pf->in[pf->i] == 'h') && (pf->arg.length = h))
		return (1);
	if (pf->in[(pf->i + 1)] && (pf->in[(pf->i + 1)] == 'l')
	&& (pf->in[pf->i] == 'l') && (pf->arg.length = ll) && pf->i++)
		return (1);
	if ((pf->in[pf->i] == 'l') && (pf->arg.length = l))
		return (1);
	if ((pf->in[pf->i] == 'j') && (pf->arg.length = j))
		return (1);
	if ((pf->in[pf->i] == 'z') && (pf->arg.length = z))
		return (1);
	return (1);
}

int		pf_parse_preci(t_printf *pf)
{
	int			start;

	pf->i++;
	pf->arg.ispreci = 1;
	if (pf->in[pf->i] && pf->in[pf->i] == '*'
	&& ((pf->arg.preci = va_arg(pf->ap, int)) || 1))
	{
		if (pf->arg.preci < 0 && !(pf->arg.ispreci = 0))
			pf->arg.preci = 0;
		if (DEBUG)
			printf("%25s %6d %10s %6c\n", "pf_parse_preci 1", pf->i, "lettre", pf->in[pf->i]);
		if (DEBUG)
			printf("%25s %6d %10s %6d\n", "pf_parse_preci 1", pf->i, "preci", pf->arg.preci);
		return (1);
	}
	start = pf->i;
	while (pf->in[pf->i])
	{
		if (DEBUG)
			printf("%25s %6d %10s %6c\n", "pf_parse_preci 2", pf->i, "lettre", pf->in[pf->i]);
		if ((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > '9')
			break;
		pf->i++;
	}
	if (pf->i - start > 0)
	{
		if (!(pf->join = ft_strsub(pf->in, start, (pf->i - start)))
		&& (pf->ret = 1))
			return (0);
	}
	else if (pf->i-- || 1)
		return (1);
	pf->i--;
	pf->arg.preci = ft_atoi(pf->join);
	ft_strdel(&pf->join);
	if (DEBUG)
		printf("%25s %6d %10s %6d\n", "pf_parse_preci", pf->i, "preci", pf->arg.preci);
	return (1);
}

int		pf_parse_width(t_printf *pf)
{
	int			start;

	if (pf->in[pf->i] && pf->in[pf->i] == '*'
	&& ((pf->arg.width = va_arg(pf->ap, int)) || 1))
	{
		if ((pf->arg.width < 0) && (pf->arg.less = 1))
			pf->arg.width = -(pf->arg.width);
		if (DEBUG)
			printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", pf->in[pf->i]);
		if (DEBUG)
			printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
		return (1);
	}
	start = pf->i;
	while (pf->in[pf->i])
	{
		if (DEBUG)
			printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", pf->in[pf->i]);
		if ((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > '9')
			break;
		pf->i++;
	}
	if (pf->i - start > 0)
		if (!(pf->join = ft_strsub(pf->in, start, (pf->i - start)))
		&& (pf->ret = 1))
			return (0);
		pf->arg.width = ft_atoi(pf->join);
		ft_strdel(&pf->join);
		if (DEBUG)
			printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
	return (1);
}
