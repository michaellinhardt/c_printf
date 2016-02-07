/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:18:38 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_join_specifier(void)
{
	t_printf		*pf;
	char			*prev;

	pf = pf_singleton(1);
	if (!pf->join)
		return (0);

		printf("%25s %6d\n\n", "join 2", pf->i);
	prev = pf->out;
	if (!(pf->out = ft_strjoin(prev, pf->join)))
		return (1);
	ft_strdel(&prev);
	ft_strdel(&pf->join);
	return (0);
}

static int	pf_join_format(const char *restrict format)
{
	t_printf		*pf;
	char			*prev;
	char			*next;

	pf = pf_singleton(1);
	if ((pf->i - pf->start) == 0)
		return (0);
		printf("%25s %6d\n\n", "join 1", pf->i);
	prev = pf->out;
	if (!(next = ft_strsub(format, pf->start, (pf->i - pf->start))))
		return (1);
	if (!(pf->out = ft_strjoin(prev, next)))
		return (1);
	pf->start = pf->i;
	ft_strdel(&prev);
	ft_strdel(&next);
	return (0);
}


int			pf_join(int from, const char *restrict format)
{
	if (from == 1 && pf_join_format(format))
		return (1);
	if (from == 2 && pf_join_specifier())
		return (1);
	return (0);
}
