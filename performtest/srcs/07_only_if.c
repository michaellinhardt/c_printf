/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_only_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:08:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/01 12:46:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void	pt_test_one_putstr_only_if(void)
{
	int		i;

	i = 0;
	pt_title("07: ONE PUTSTR - ONLY IF");
	while (d->again--)
		pt_parse_one_putstr_only_if();
}

void		pt_parse_one_putstr_only_if(void)
{
	int			s;
	int			e;
	char		*str = NULL;
	char		*t = NULL;
	char		*t2 = NULL;
	int			i = -1;

	str = ft_strnew(0);
	s = 0;
	while (d->input3[++i])
	{
		if (d->input3[i] == '%')
		{
			e = i;
			t = str;
			t2 = ft_strsub(d->input3, s, (e - s));
			str = ft_strjoin(t, t2);
			ft_strdel(&t);
			ft_strdel(&t2);
			i++;
			pt_get_handler07(d->input3[i], &str);
			s = (i + 1);
		}
	}
	ft_putstr(str);
	ft_strdel(&str);
}
