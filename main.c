/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/26 01:07:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_test(void)
{
	int i = 0;
	double j = 0.012;

	ft_printf("%E\n", (double)j);
	printf("%E\n", j);
}

int				main(int argc, char **argv)
{
	if (argc && argv)
		;
	pf_test();
	return (0);
}
