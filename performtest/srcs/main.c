/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/31 20:33:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

int		main(int argc, char **argv)
{
	if (argc && argv[1])
		pt_run(argv[1]);
	else
		printf("Syntaxe: ./a.out 1, 2, 3... 5");
	return (0);
}

void		pt_run(char *test)
{
	pt_set_data();
	pt_set_route(ft_atoi(test));
	pt_free_data();
}

void		pt_set_route(int test)
{
	if (test == 1)
		pt_test_only_putchar();
	if (test == 2)
		pt_test_multiple_putstr();
	if (test == 3)
		pt_test_one_putstr();
	if (test == 4)
		pt_test_one_putstr04();
	if (test == 5)
		pt_test_one_putstr05();
	if (test == 6)
		pt_test_one_putstr_tab_pointeur();
	// if (test == 7)
	// 	pt_test_one_putstr_only_if();
}

void		pt_set_data(void)
{
	d = (t_data *)malloc(sizeof(t_data) * 1);
	d->i = (int *)malloc(sizeof(int) * (5));
	d->s = (char **)malloc(sizeof(char *) * (5));
	d->i[0] = 11899;
	d->i[1] = -3805;
	d->i[2] = 183023;
	d->i[3] = 1027;
	d->i[4] = 4354354;
	d->s[0] = ft_strdup("ft_strdup1");
	d->s[1] = ft_strdup("ft_strdup2");
	d->s[2] = ft_strdup("ft_strdup3");
	d->s[3] = ft_strdup("ft_strdup4");
	d->s[4] = ft_strdup("ft_strdup5");
	d->again = 4000000;
	d->input = ft_strdup("Ceci est un lorem ipsum de printf, %0d lorem %1d ipsum %0s!\n%1s et %2d ou %2s ou %3d et %3s et enfin %4s pour %4d");
	d->input2 = ft_strdup("Ceci est un lorem ipsum de printf, %0+--   #0d lorem %1--+ -#d ipsum %0 s!\n%1#s et %2 0d ou %2-s ou %3+d et %3  s et enfin %4#0-+ s pour %4-+ 0#d");
	d->input3 = ft_strdup(" mot %% mot %s mot %S mot %p mot %d mot %D mot %i mot %o mot %O mot %u mot %U mot %x mot %X mot %c mot %C mot %b mot %f mot %n");
}

void		pt_free_data(void)
{
	int		i;

	i = -1;
	while (++i < 5)
		ft_strdel(&d->s[i]);
	ft_strdel(&d->input);
	ft_strdel(&d->input2);
	ft_strdel(&d->input3);
	free(d->s);
	free(d->i);
	free(d);
}
