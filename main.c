/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/02 19:36:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_test(void)
{
	ft_printf("%0{col\n");
	ft_printf("%1{col\n");
	ft_printf("%2{col\n");
	ft_printf("%3{col\n");
	ft_printf("%4{col\n");
	ft_printf("%5{col\n");
}

int				main(int argc, char **argv)
{
	if (argc && argv)
		;
	pf_test();
	return (0);
}
