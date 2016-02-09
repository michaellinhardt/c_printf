/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/02 07:33:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_build_invalid(t_printf *pf)
{
	printf("\n%25s %6d %10s %6c\n", "pf_build_invalid", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strnew(0)))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	if (pf->arg.width)
		pf->arg.width--;
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	return (0);
}

int		pf_build_modulo(t_printf *pf)
{
	printf("\n%25s %6d %10s %6c\n", "pf_build_modulo", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strdup("%")))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.preci = 0;
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	pf->valid = 1;
	return (0);
}

int		pf_build_string(t_printf *pf)
{
	printf("\n%25s %6d %10s %6c\n", "pf_build_string", pf->i, "lettre", pf->in[pf->i]);
	if (pf->arg.ispreci && !(pf->join = ft_strsub(va_arg(pf->ap, char *), 0, pf->arg.preci)))
		return (1);
	if (!pf->arg.ispreci && !(pf->join = ft_strdup(va_arg(pf->ap, char *))))
		return (1);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	pf->valid = 1;
	return (0);
}

int		pf_build_int(t_printf *pf)
{
	int		i;
	int		len;
	char	*tmp;

	i = va_arg(pf->ap, int);
	printf("\n%25s %6d %10s %6c\n", "pf_build_char", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_itoa(i)))
		return (1);
	pf->arg.diez = 0;
	if (i < 0)
	{
		pf->arg.more = 0;
		pf->arg.space = 0;
	}
	else if (pf->arg.more)
		pf->arg.space = 0;
	if (pf->arg.preci && pf->arg.preci > (int)ft_strlen(pf->join))
	{
		if (!(tmp = ft_strnew(pf->arg.preci)))
			return (1);
		i = -1;
		pf->j = -1;
		len = (int)ft_strlen(pf->join);
		while (++i < pf->arg.preci)
			tmp[i] = ((pf->arg.preci - i) > len) ? '0' : pf->join[++pf->j];
		ft_strdel(&pf->join);
		pf->join = tmp;
	}
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	pf->valid = 1;
	return (0);
}

int		pf_build_char(t_printf *pf)
{
	printf("\n%25s %6d %10s %6c\n", "pf_build_char", pf->i, "lettre", pf->in[pf->i]);
	if (!(pf->join = ft_strnew(1)))
		return (1);
	pf->join[0] = (char)va_arg(pf->ap, int);
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	pf->arg.preci = 0;
	if (pf_build_format(pf))
		return (1);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	pf->valid = 1;
	return (0);
}
