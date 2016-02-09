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

static int		pf_fake(t_printf *pf)
{
	pf->arg.more = 1;
	printf("%25s %6d %10s %6c\n", "pf_fake", pf->i, "lettre", pf->in[pf->i]);
	return (0);
}

static int		pf_parse_modulo(t_printf *pf)
{
	(void)pf->in;
	printf("%25s %6d %10s %6c\n", "pf_parse_modulo", pf->i, "lettre", pf->in[pf->i]);
	if (!pf->arg.modulo && (pf->arg.modulo = 1))
		return (1);
	if (pf_build_modulo(pf))
		pf->ret = 1;
	return (0);
}

static int		pf_parse_flag(t_printf *pf)
{
	printf("%25s %6d %10s %6c\n", "pf_parse_flag", pf->i, "lettre", pf->in[pf->i]);
	if ((pf->in[pf->i] == '#') && (pf->arg.diez = 1))
		return (1);
	if ((pf->in[pf->i] == '0') && (pf->arg.zero = 1))
		return (1);
	if ((pf->in[pf->i] == '+') && (pf->arg.more = 1))
		return (1);
	if ((pf->in[pf->i] == '-') && (pf->arg.less = 1))
		return (1);
	if ((pf->in[pf->i] == ' ') && (pf->arg.space = 1))
		return (1);
	// if ((pf->in[pf->i] == '{') && (pf->arg.col = 1))
	// 	return (1);
	return (1);
}

static int		pf_parse_preci(t_printf *pf)
{
	int			start;

	pf->i++;
	pf->arg.ispreci = 1;
	if (pf->in[pf->i] && pf->in[pf->i] == '*'
	&& ((pf->arg.preci = va_arg(pf->ap, int)) || 1))
	{
		printf("%25s %6d %10s %6c\n", "pf_parse_preci 1", pf->i, "lettre", pf->in[pf->i]);
		printf("%25s %6d %10s %6d\n", "pf_parse_preci 1", pf->i, "preci", pf->arg.preci);
		return (1);
	}
	start = pf->i;
	while (pf->in[pf->i])
	{
		printf("%25s %6d %10s %6c\n", "pf_parse_preci 2", pf->i, "lettre", pf->in[pf->i]);
		if ((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > '9')
			break;
		pf->i++;
	}
	if (pf->i - start > 0)
	{
		if (!(pf->join = ft_strsub(pf->in, start, (pf->i - start)))
		&& (pf->ret = 1))
			return (0);
	}
	else if (pf->i-- || 1)
		return (1);
	pf->i--;
	pf->arg.preci = ft_atoi(pf->join);
	ft_strdel(&pf->join);
	printf("%25s %6d %10s %6d\n", "pf_parse_preci", pf->i, "preci", pf->arg.preci);
	return (1);
}

static int		pf_parse_width(t_printf *pf)
{
	int			start;

	if (pf->in[pf->i] && pf->in[pf->i] == '*'
	&& ((pf->arg.width = va_arg(pf->ap, int)) || 1))
	{
		printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", pf->in[pf->i]);
		printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
		return (1);
	}
	start = pf->i;
	while (pf->in[pf->i])
	{
		printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", pf->in[pf->i]);
		if ((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > '9')
			break;
		pf->i++;
	}
	if (pf->i - start > 0)
		if (!(pf->join = ft_strsub(pf->in, start, (pf->i - start)))
		&& (pf->ret = 1))
			return (0);
		pf->arg.width = ft_atoi(pf->join);
		ft_strdel(&pf->join);
		printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
	return (1);
}

static void		pf_parse_specifier_init(int (**spe)(t_printf *))
{
	spe['%'] = &pf_parse_modulo;
	spe['s'] = &pf_build_string;
	spe['c'] = &pf_build_char;
	spe['i'] = &pf_build_int;
	spe['d'] = &pf_build_int;

	spe['S'] = &pf_fake;
	spe['C'] = &pf_fake;

	spe['p'] = &pf_fake;
	spe['D'] = &pf_fake;
	spe['o'] = &pf_fake;
	spe['O'] = &pf_fake;
	spe['u'] = &pf_fake;
	spe['U'] = &pf_fake;
	spe['x'] = &pf_fake;
	spe['X'] = &pf_fake;
	// spe['{'] = &pf_parse_flag;
	spe['#'] = &pf_parse_flag;
	spe['0'] = &pf_parse_flag;
	spe['+'] = &pf_parse_flag;
	spe['-'] = &pf_parse_flag;
	spe[' '] = &pf_parse_flag;

	spe['*'] = &pf_parse_width;
	spe['.'] = &pf_parse_preci;
	// int i = -1;
	// while (++i < 128)
	// 	if (spe[i])
		// printf("%d\n", i);
}

static int		pf_parse_specifier(t_printf *pf)
{
	static int		(*spe[128])(t_printf *) = {NULL};

	if (!spe['%'])
		pf_parse_specifier_init(spe);
	while (pf->in[pf->i])
	{
		if ((int)pf->in[pf->i] > '0' && (int)pf->in[pf->i] < 58
			&& !(pf_parse_width(pf)))
		{
			printf("\n%25s %6d %10s %6c\n", "fin de specifier 1", pf->i, "lettre", pf->in[pf->i]);
			break;
		}
		else if (((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > 57)
		&& (!spe[(int)(pf->in[pf->i])]))
		{
			printf("\n%25s %6d %10s %6c\n", "fin de specifier 3", pf->i, "lettre", pf->in[pf->i]);
			break;
		}
		else if (pf->in[pf->i] && spe[(int)(pf->in[pf->i])]
			&& printf("\n%25s %6d %10s %6c\n", "pf_parse_specifier", pf->i, "verif", pf->in[pf->i]) && !(spe[(int)(pf->in[pf->i])](pf)))
		{
			printf("\n%25s %6d %10s %6c\n", "fin de specifier 2", pf->i, "lettre", pf->in[pf->i]);
			break;
		}
		pf->i++;
		printf("\n%25s %6d %10s %6c\n", "pf_parse_specifier", pf->i, "incre", pf->in[pf->i]);
	}
	if (pf->valid == 0 && pf_build_invalid(pf))
		return (1);
	if (pf->ret || (!pf->ret && pf_join(pf, 2)))
		return (1);
	pf->start = (pf->valid) ? pf->i + 1 : pf->i ;
	printf("%25s %6d %10s %6c\n", "pf_parse_specifier", pf->i, "end", pf->in[pf->i]);
	return (0);
}

int				pf_parse(t_printf *pf)
{

	while (pf->in[pf->i])
	{
		printf("%25s %6d %10s %6c\n", "pf_parse", pf->i, "lettre", pf->in[pf->i]);
		if ((pf->in[pf->i] == '%') && (pf_join(pf, 1)
		|| pf_parse_specifier(pf)))
			return (1);
		if (!pf->in[pf->i])
			break;
		pf->i++;
	}
	if ((pf->i - pf->start) > 0 && pf_join(pf, 1))
		return (1);
	if (pf_join(pf, 2))
		return (1);
	// char		*tmp;
	// tmp = va_arg(pf->ap, char *);
	// printf("\npf->ap %s\n", tmp);
	return (0);
}
