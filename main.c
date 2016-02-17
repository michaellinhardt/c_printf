/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/17 03:28:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}

static void	ft_putwstr_fd(wchar_t const *str, int fd)
{
	while (*str)
		ft_putwchar_fd(*str++, fd);
}

int		main(int argc, char **argv)
{
	if (argc && argv)
		;

	char *l = setlocale(LC_ALL, "en_US.UTF-8");

	// wchar_t str[] = L"αÁ±≥";

	// tab[0] = ft_strdup("0xxxxxxx");
	// tab[1] = ft_strdup("110xxxxx10xxxxxx");
	// tab[2] = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	// tab[3] = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");

	wchar_t ws[] = L"≥±Áα";
	wchar_t *ws2;
	char s[5];

	char *str;
	char *tmp;

	str = ft_strdup("magie -> ");

	ws2 = ws;

	while (*ws2)
	{
		if (*ws2 <= 0x7F)
		{
			int i = 4;
			while (s[--i])
				s[i] = (i == 0) ? (char)*ws2 : '\0';
		}
		else if (*ws2 <= 0x7FF)
		{
			s[0] = (*ws2 >> 6) + 0xC0;
			s[1] = (*ws2 & 0x3F) + 0x80;
			s[2] = '\0';
		}
		else if (*ws2 <= 0xFFFF)
		{
			s[0] = (*ws2 >> 12) + 0xE0;
			s[1] = ((*ws2 >> 6) & 0x3F) + 0x80;
			s[2] = (*ws2 & 0x3F) + 0x80;
			s[3] = '\0';
		}
		else if (*ws2 <= 0x10FFFF)
		{
			s[0] = (*ws2 >> 18) + 0xF0;
			s[1] = ((*ws2 >> 12) & 0x3F) + 0x80;
			s[2] = ((*ws2 >> 6) & 0x3F) + 0x80;
			s[3] = (*ws2 & 0x3F) + 0x80;
			s[4] = '\0';
		}
		tmp = str;
		str = ft_strjoin(tmp, s);
		ft_strdel(&tmp);
		if (*ws2++)
			;
	}
	printf("%s\n", str);
	ft_strdel(&str);
	ft_strdel(&l);
	// printf(" - ret: %d\n", ft_printf("@main_ftprintf: % 33....5.+#d", 256));
	// printf(" - ret: %d\n", printf("@main_ftprintf: % 33....5.+#d", 256));
	return (0);
}
