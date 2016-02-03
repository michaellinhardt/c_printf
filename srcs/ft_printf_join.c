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

static int	pf_join_format(const char *restrict format)
{
	t_printf		*pf;
	char			*prev;
	char			*next;

	pf = pf_singleton(1);
	prev = pf->join;
	if (!(next = ft_strsub(format, pf->start, pf->i)))
		return (1);
	if (!(pf->join = ft_strjoin(prev, next)))
		return (1);
	ft_strdel(&prev);
	ft_strdel(&next);
	return (0);
}


int			pf_join(int from, const char *restrict format)
{
	if (from == 1 && pf_join_format(format))
		return (1);
	return (0);
}
