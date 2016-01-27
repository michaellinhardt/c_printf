/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 04:21:04 by mlinhard         ###   ########.fr       */
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
	pt_init_stats();
	pt_set_route(ft_atoi(test));
	pt_free_data();
}

void		pt_set_route(int test)
{
	if (test == 1)
		pt_test_only_write();
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
	d->again = 100000;
	d->input = ft_strdup("Ceci est un lorem ipsum de printf, %0d lorem %1d ipsum %0s!\n%1s et %2d ou %2s ou %3d et %3s et enfin %4s pour %4d!");
}

void		pt_init_stats(void)
{
	d->write = 0;
	d->malloc = 0;
}

void		pt_free_data(void)
{
	int		i;

	i = -1;
	while (++i < 5)
		ft_strdel(&d->s[i]);
	ft_strdel(&d->input);
	free(d->s);
	free(d->i);
	free(d);
}
