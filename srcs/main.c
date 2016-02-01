/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/01 14:54:11 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	char	*s3;

	if (argc && argv)
		;
	s1 = ft_strdup("s1lala");
	s2 = ft_strdup("s2ahah");
	s3 = ft_strdup("s3hihi");

	ft_printf(s1);

	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);
	return (0);
}
