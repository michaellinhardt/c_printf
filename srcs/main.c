/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/08 04:13:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	// int		test = 1;
	// char	*s1;
	// s1 = ft_strdup("%%abcd%*+-54-%a%%\n");

	// while (test--)
	// 	ft_printf(s1);
	// ft_strdel(&s1);

	// if (argc && argv)
	// 	;


	char	*s1;
	char	*s2;
	char	*s3;
	int		ret;

	if (argc && argv)
		;
	s1 = ft_strdup("abcd%-*%a%%");
	s2 = ft_strdup("s2ahah");
	s3 = ft_strdup("%     ");

	ret = ft_printf(s1, 3);
	printf("\n\nRETURN: %d\n", ret);
	printf("\nTEST1: %*s\n", 5, ".");
	printf("\nTEST2: %s\n", s3);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);

	return (0);
}
