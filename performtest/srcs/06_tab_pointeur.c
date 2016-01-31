/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_03_only_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:08:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/31 03:43:08 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void	pt_test_one_putstr_tab_pointeur(void)
{
	int		i;

	i = 0;
	pt_title("06: ONE PUTSTR - TAB POINTEUR");
	// if (V)
	// {
	// 	printf("*pt_parse_one_putstr(d->input3) ->\n\tSTRING: malloc for later \n\t%%s: malloc for later\n\t%%d: malloc for later\n\n");
	// 	printf("*pt_parse_option_only_if(d->input3[i]) ->\n\tuse multiple if to set the conversion options\n\n");
	// }
	while (d->again--)
		pt_parse_one_putstr_tab_pointeur();
}

void		pt_parse_one_putstr_tab_pointeur(void)
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
			pt_get_handler06(d->input3[(i + 1)], &str);
			s = i + 2;
		}
	}
	ft_putstr(str);
	ft_strdel(&str);
}
