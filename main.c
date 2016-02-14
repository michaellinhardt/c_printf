/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/14 06:28:53 by mlinhard         ###   ########.fr       */
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
	long long int	s3;
	// wchar_t s4[50] = L"Salut G\x82rard !";
	char	*src;
	int		taille;
	int		ret = 0;

	intmax_t	nbr = 'c'; nbr += 1;
	// printf("sizeof: %i\n", nbr);

	ret += 1;
	if (argc && argv)
		;
	taille = 10;
	s1 = ft_strdup("%i!\n");
	s2 = ft_strdup("s2ahah");
	src = s1;

	printf(" - ret: %d ", ft_printf("%d", -42));
	printf("\n");
	printf(" - ret: %d ", printf("%d", -42));
	printf("\n");
	printf("\n");

	ft_printf("%X", -42);
	printf("\n");
	printf("%X", -42);
	printf("\n");
	printf("\n");

	s3 = (unsigned int)&s1;
	// printf("\n%p\n", s1);
	// printf("0x");
	// printf("%llx\n", s3);

	// printf("%#5.4o\n", 9);

	// printf("\n\nRETURN: %d\n", ret);
	ft_strdel(&s1);
	ft_strdel(&s2);
	// ft_strdel(&s3);

	return (0);
}
