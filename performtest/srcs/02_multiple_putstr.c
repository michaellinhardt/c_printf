/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_only_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 07:19:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void	pt_test_multiple_putstr(void)
{
	int		i;

	i = 0;
	pt_title("02: MULTIPLE PUTSTR");
	if (V)
		printf("*pt_parse_multiple_putstr(d->input) ->\n\tSTRING: one time with putstr \n\t%%s: one time with putstr\n\t%%d: one time with itoa\n\n");
	while (d->again--)
		pt_parse_multiple_putstr();
}

void		pt_parse_multiple_putstr(void)
{
	int		i;
	int		s;
	int		e;
	char	*str = NULL;

	i = -1;
	s = 0;
	while (d->input[++i])
	{
		if (d->input[i] == '%')
		{
			e = i;
			str = ft_strsub(d->input, s, (e - s));
			ft_putstr(str);
			ft_strdel(&str);
			if (d->input[(i+2)] == 'd')
				ft_putnbr(d->i[(ft_atoi(&d->input[(i+1)]))]);
			else
				ft_putstr(d->s[(ft_atoi(&d->input[(i+1)]))]);
			i += 2;
			s = i + 1;
		}
	}
}