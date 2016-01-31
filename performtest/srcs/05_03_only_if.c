/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_03_only_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:08:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/31 04:14:54 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void	pt_test_one_putstr05(void)
{
	int		i;

	i = 0;
	pt_title("04_03: ONE PUTSTR - OPTION: ONLY IF & MALLOC");
	if (V)
	{
		printf("*pt_parse_one_putstr(d->input2) ->\n\tSTRING: malloc for later \n\t%%s: malloc for later\n\t%%d: malloc for later\n\n");
		printf("*pt_parse_option_only_if(d->input2[i]) ->\n\tuse multiple if to set the conversion options\n\n");
	}
	while (d->again--)
		pt_parse_one_putstr05();
}

void		pt_parse_one_putstr05(void)
{
	int			s;
	int			e;
	char		*str = NULL;
	char		*t = NULL;
	char		*t2 = NULL;
	t_convert	*conv;

	str = ft_strnew(0);
	conv = (t_convert *)malloc(sizeof(t_convert) * 1);
	pt_option_reset(conv);
	conv->i = -1;
	s = 0;
	while (d->input2[++conv->i])
	{
		if (d->input2[conv->i] == '%')
		{
			e = conv->i;
			t = str;
			t2 = ft_strsub(d->input2, s, (e - s));
			str = ft_strjoin(t, t2);
			ft_strdel(&t);
			ft_strdel(&t2);
			pt_parse_option_only_if(conv);
			pt_join_conv(conv, &str);
			pt_option_reset(conv);
			s = conv->i + 1;
		}
	}
	ft_memdel((void **)&conv);
	ft_putstr(str);
	ft_strdel(&str);
}

void		pt_parse_option_only_if05(t_convert *conv)
{
	conv->id = ft_atoi(&d->input2[++conv->i]);
	while (d->input2[++conv->i])
	{
		if (d->input2[conv->i] == '-')
			conv->flags_less = 1;
		else if (d->input2[conv->i] == '+')
			conv->flags_more = 1;
		else if (d->input2[conv->i] == ' ')
			conv->flags_space = 1;
		else if (d->input2[conv->i] == '#')
			conv->flags_diez = 1;
		else if (d->input2[conv->i] == '0')
			conv->flags_zero = 1;
		else if (d->input2[conv->i] == 's')
		{
			conv->specifier = 's';
			break;
		}
		else if (d->input2[conv->i] == 'd')
		{
			conv->specifier = 'd';
			break;
		}
		else
			break;
	}
}
