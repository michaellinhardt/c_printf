/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 01:49:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_test2(int i)
{
	int r1;
	int r2;
	char lol[2048];

	r1 = ft_printf("%C", i);
	r2 = sprintf(lol, "%C", i);
	if (r1 != r2)
	{
		printf("ERREUR: %d (%d - %d)\n", i, r1, r2);
		exit (0);
	}
}

static void		ft_test1(int i)
{
	int r1;
	char test[2048];
	static int start = 0;

	r1 = sprintf(test, "%C", i);
	if (r1 == -1 && start == 0)
	{
		printf("**********\n%d à\n", i);
		start = 1;
	}
	else if (r1 > -1 && start == 1)
	{
		start = 0;
		printf("%d\n**********\n", (i + 1));
	}
}

int			main(void)
{
	char* l = setlocale(LC_ALL, "en_US.UTF-8");
	int i = 1114114;
	int r1;
	char test[2048];

	while (--i > -3)
		ft_test2(i);

	(void)l;
	return (0);
}

