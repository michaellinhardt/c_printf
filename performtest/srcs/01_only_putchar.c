/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_only_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 07:21:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void	pt_test_only_putchar(void)
{
	int		i;

	i = 0;
	pt_title("01: ONLY PUTCHAR");
	if (V)
		printf("*pt_parse_only_putchar(d->input) ->\n\tSTRING: one by one with putchar\n\t%%s: one time with putstr\n\t%%d: one by one with putnbr\n\n");
	while (d->again--)
		pt_parse_only_putchar();
}

void		pt_parse_only_putchar(void)
{
	int		i;

	i = -1;
	while (d->input[++i])
	{
		if (d->input[i] != '%')
			ft_putchar(d->input[i]);
		else
		{
			if (d->input[(i+2)] == 'd')
				ft_putnbr(d->i[(ft_atoi(&d->input[(i+1)]))]);
			else
				ft_putstr(d->s[(ft_atoi(&d->input[(i+1)]))]);
			i += 2;
		}
	}
}