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

int		pf_parse(const char *restrict format, ...)
{
	t_printf	*pf;

	pf = pf_singleton(1);
	while (format[pf->i++])
		if (format[pf->i] == '%')
			printf("modulo\n");
	if ((pf->i - pf->start) > 0 && pf_join(1, format))
		return (-1);
	return (0);
}
