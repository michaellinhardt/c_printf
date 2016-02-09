/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/09 04:11:00 by mlinhard         ###   ########.fr       */
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
	// wchar_t s4[50] = L"Salut G\x82rard !";
	char	*src;
	int		taille;
	int		ret = 0;

	ret += 1;
	if (argc && argv)
		;
	taille = 10;
	s1 = ft_strdup("%.3d!\n");
	s2 = ft_strdup("s2ahah");
	s3 = ft_strdup("%     ");
	src = s1;

	ft_printf(s1, 42);
	printf(s1, 42);

	// printf("\n\nRETURN: %d\n", ret);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);

	return (0);
}
