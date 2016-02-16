/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/16 05:27:42 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	if (argc && argv)
		;

	char *l = setlocale(LC_ALL, "en_US.UTF-8");
	int test;
	int i;

	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}

	wchar_t str[] = L"αÁ±≥";

	i = 0;
	while (str[i])
	{
		test = (int)str[i];
		printf("%d - %C\n", test, str[i]);
		write(1, &test, 1);
		i++;
	}

	// printf("-> %C", 945);
	printf("ret: %d\n", printf("FU %ls\n", L"Á±≥"));
	printf("ret: %d\n", printf("FU %d\n", L'α'));

	test = (int)L'α';

	printf("ret: %d\n", printf("FU %d\n", str[0]));


	ft_strdel(&l);

	// printf(" - ret: %d\n", ft_printf("@main_ftprintf: % 33....5.+#d", 256));
	// printf(" - ret: %d\n", printf("@main_ftprintf: % 33....5.+#d", 256));
	return (0);
}
