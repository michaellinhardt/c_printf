/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:24:46 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_printf	*pf_singleton(int last)
{
	static t_printf		pf;

	if (!last)
	{
		pf.i = 0;
		pf.start = 0;
		pf.ret = -1;
	}
	return (&pf);
}
