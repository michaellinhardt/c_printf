/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 00:01:24 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/10 00:15:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_base_len(long int n, size_t lb)
{
	size_t	l;

	l = (n <= 0);
	n = (n < 0) ? -n : n;
	while (n != 0)
	{
		n /= lb;
		l++;
	}
	return (l);
}

static void		ft_itoa_base_fill(long int bn, char *s, const char *b, size_t lb)
{
	if (bn == 0)
		*s = *b;
	while (bn != 0)
	{
		*s-- = *(b + ((unsigned long int)bn % lb));
		bn /= lb;
	}
}

char			*ft_itoa_base(int n, const char *b)
{
	char		*s;
	size_t		l;
	long int	bn;
	size_t		lb;

	bn = (long int)n;
	lb = ft_strlen(b);
	l = ft_itoa_base_len(bn, lb);
	if (!(s = ft_strnew(l)))
		return (NULL);
	if (bn < 0 && (*s = '-'))
		bn = -(bn);
	ft_itoa_base_fill(bn, s + l - 1, b, lb);
	return (s);
}
