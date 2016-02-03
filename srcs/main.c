/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/03 01:54:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		ret;

	if (argc && argv)
		;
	s1 = ft_strdup("s1lala");
	s2 = ft_strdup("s2ahah");
	s3 = ft_strdup("s3hihi");

	ret = ft_printf(s1, s2);
	printf("\n\nRETURN: %d\n", ret);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);
	return (0);
}
