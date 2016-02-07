/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/08 00:47:37 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		ret;
	int		test = 5;

	if (argc && argv)
		;
	s1 = ft_strdup("abcd%*+-54-%a%%");
	s2 = ft_strdup("s2ahah");
	s3 = ft_strdup("s3hihi");
	test += 1;

	ret = ft_printf(s1, test);
	printf("\n\nRETURN: %d\n", ret);
	printf("%s %*%\n", "TEST REAL PRINTF", 5);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);
	return (0);
}
