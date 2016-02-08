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

int		pf_build_modulo(t_printf *pf)
{
	printf("\n%25s %6d %10s %6s\n", "pf_build_modulo", pf->i, "lettre", "NA");
	if (!(pf->join = ft_strdup("%%")))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.preci = 0;
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	return (0);
}
