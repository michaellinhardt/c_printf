/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/31 02:16:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;

	va_start(ap, format);
	printf("%s\n", va_arg(ap, char *));
	printf("%s\n", va_arg(ap, char *));
	printf("%s\n", va_arg(ap, char *));
	printf("%s\n", va_arg(ap, char *));
	va_end(ap);
	return (0);
}
