/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_one_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/01 13:50:32 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"
#include <unistd.h>

void	pt_test_one_putstr08(void)
{
	int		i;

	i = 0;
	pt_title("08: ONE WRITE");
	while (d->again--)
		pt_parse_one_putstr08();
}

void		pt_parse_one_putstr08(void)
{
	int		i;
	int		s;
	int		e;
	char	*str = NULL;
	char	*t = NULL;
	char	*t2 = NULL;

	i = -1;
	s = 0;
	str = ft_strnew(0);
	while (d->input[++i])
	{
		if (d->input[i] == '%')
		{
			e = i;
			t = str;
			t2 = ft_strsub(d->input, s, (e - s));
			str = ft_strjoin(t, t2);
			ft_strdel(&t);
			ft_strdel(&t2);
			if (d->input[(i+2)] == 'd')
			{
				t = str;
				t2 = ft_itoa(d->i[(ft_atoi(&d->input[(i+1)]))]);
				str = ft_strjoin(t, t2);
				ft_strdel(&t);
				ft_strdel(&t2);
			}
			else
			{
				t = str;
				str = ft_strjoin(t, d->s[(ft_atoi(&d->input[(i+1)]))]);
				ft_strdel(&t);
			}
			i += 2;
			s = i + 1;
		}
	}
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
}
