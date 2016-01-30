/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/30 22:47:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void		pt_title(char *title)
{
	printf("\n\n==================== * ====================\n");
	printf("\t\t\t %s \n", title);
	printf("==================== * ====================\n");
}

void		pt_option_reset(t_convert *conv)
{
		conv->flags_less = 0;
		conv->flags_more = 0;
		conv->flags_space = 0;
		conv->flags_diez = 0;
		conv->flags_zero = 0;
}

void		pt_join_conv(t_convert *conv, char **str)
{
	char	*t;
	char	*t2;

	t = *str;
	if (conv->specifier == 's')
		t2 = d->s[conv->id];
	if (conv->specifier == 'd')
		t2 = ft_itoa(d->i[conv->id]);
	*str = ft_strjoin(t, t2);
	ft_strdel(&t);
	if (conv->specifier == 'd')
		ft_strdel(&t2);
}