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

static int	pf_parse_specifier(const char *restrict format)
{
	t_printf	*pf;

	if (format)
		pf = pf_singleton(1);
	return (0);
}

int		pf_parse(const char *restrict format)
{
	t_printf	*pf;

	pf = pf_singleton(1);
	while (format[pf->i++])
	{
		if ((format[pf->i] == '%') && pf_parse_specifier(format))
			return (1);
	}
	if ((pf->i - pf->start) > 0 && pf_join(1, format))
		return (-1);
	// char		*tmp;
	// tmp = va_arg(pf->ap, char *);
	// printf("\npf->ap %s\n", tmp);
	return (0);
}
