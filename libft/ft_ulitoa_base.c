/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 23:01:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/10 23:01:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_base_len(unsigned long int n, size_t lb)
{
	size_t	l;

	l = (n <= 0);
	while (n != 0)
	{
		n /= lb;
		l++;
	}
	return (l);
}

static void		ft_itoa_base_fill(unsigned long int bn, char *s, const char *b, size_t lb)
{
	if (bn == 0)
		*s = *b;
	while (bn != 0)
	{
		*s-- = *(b + ((unsigned long int)bn % lb));
		bn /= lb;
	}
}

char			*ft_ulitoa_base(unsigned long int n, const char *b)
{
	char				*s;
	size_t				l;
	unsigned long int	bn;
	size_t				lb;

	bn = n;
	lb = ft_strlen(b);
	l = ft_itoa_base_len(bn, lb);
	if (!(s = ft_strnew(l)))
		return (NULL);
	ft_itoa_base_fill(bn, s + l - 1, b, lb);
	return (s);
}
