/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2016/02/02 07:33:40 by mlinhard         ###   ########.fr       */
/*   Updated: 2016/02/02 07:33:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_build_format_width(t_printf *pf)
{
	int		start;
	int		i;
	char	c;
	char	*tmp;

	if (pf->arg.width < ft_strlen(pf->join))
		return (0);
	start = (pf->arg.less) ? 0 : (pf->arg.width - ft_strlen(pf->join));
	c = (pf->arg.zero) ? '0' : ' ';
	tmp = pf->join;
	pf->join = ft_strnew(pf->arg.width);
	i = -1;
	pf->j = 0;
	while (++i < pf->arg.width)
	{
		pf->join[i] = (i < start || !(tmp[pf->j])) ? c : tmp[pf->j++];
	}
	ft_strdel(&tmp);
	printf("%25s %6d %10s %6d\n", "pf_build_format_width", pf->i, "start", start);
	printf("%25s %6d %10s %6c\n", "pf_build_format_width", pf->i, "char", c);
	return (0);
}

int			pf_build_format(t_printf *pf)
{
	if (!pf->join)
		return (1);
	if (pf->arg.width && pf_build_format_width(pf))
		return (1);
	return (0);
}
