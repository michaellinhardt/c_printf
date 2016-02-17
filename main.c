/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/17 06:04:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
// #include <limits.h>

int		main(int argc, char **argv)
{
	if (argc && argv)
		;

	char *l = setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t ws[] = L"≥±Áα";
	wchar_t wc = L'≥';

	printf(" - ret: %d\n", ft_printf("ok %.9S lol %.2C %s", ws, wc, "oooooook"));
	printf(" - ret: %d\n", printf("ok %.9S lol %.2C %s", ws, wc, "oooooook"));

	ft_strdel(&l);
	return (0);
}
