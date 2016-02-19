/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/19 04:00:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	if (argc && argv)
		;

	long double i;
	i = 1.537895;
	printf(" - ret: %d\n", ft_printf("%#1.1Lf", (double)i));
	printf(" - ret: %d\n", printf("%#1.1Lf", (double)i));

	return (0);
}
