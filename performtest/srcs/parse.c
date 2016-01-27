/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 07:23:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void		pt_parse_only_putchar(void)
{
	int		i;

	i = -1;
	while (d->input[++i])
	{
		if (d->input[i] != '%')
			ft_putchar(d->input[i]), d->putchar++;
		else
		{
			if (d->input[(i+2)] == 'd')
				ft_putnbr(d->i[(ft_atoi(&d->input[(i+1)]))]), d->putnbr++,
				 d->atoi++;
			else
				ft_putstr(d->s[(ft_atoi(&d->input[(i+1)]))]), d->putnbr++,
				 d->atoi++;
			i += 2;
		}
	}
}

void		pt_parse_multiple_putstr(void)
{
	int		i;
	int		s;
	int		e;

	i = -1;
	while (d->input[++i])
	{
		if (d->input[i] != '%')
			ft_putchar(d->input[i]), d->putchar++;
		else
		{
			if (d->input[(i+2)] == 'd')
				ft_putnbr(d->i[(ft_atoi(&d->input[(i+1)]))]), d->putnbr++,
				 d->atoi++;
			else
				ft_putstr(d->s[(ft_atoi(&d->input[(i+1)]))]), d->putnbr++,
				 d->atoi++;
			i += 2;
		}
	}
}