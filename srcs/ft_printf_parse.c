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

static int		pf_fake(const char *restrict format)
{
	t_printf		*pf;

	(void)format;
	pf = pf_singleton(1);
		// printf("%25s %6d %10s %6c\n", "pf_fake", pf->i, "lettre", format[pf->i]);
	return (1);
}

static int		pf_save_modulo(void)
{
	t_printf		*pf;

	pf = pf_singleton(1);
		// printf("%25s %6d %10s %6s\n", "pf_save_modulo", pf->i, "lettre", "NA");
	pf->join = ft_strdup("%");
	pf->arg.more = 0;
	pf->arg.space = 0;
	pf->arg.diez = 0;
	// printf("%d\n", pf->arg.diez);
	// printf("%d\n", pf->arg.zero);
	// printf("%d\n", pf->arg.more);
	// printf("%d\n", pf->arg.less);
	// printf("%d\n", pf->arg.space);
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	return (0);
}

static int		pf_parse_modulo(const char *restrict format)
{
	t_printf		*pf;

	(void)format;
	pf = pf_singleton(1);
		// printf("%25s %6d %10s %6c\n", "pf_parse_modulo", pf->i, "lettre", format[pf->i]);
	if (!pf->arg.modulo && (pf->arg.modulo = 1))
		return (1);
	if (pf_save_modulo())
		pf->ret = 1;
	return (0);
}

static int		pf_parse_flag(const char *restrict format)
{
	t_printf		*pf;

	pf = pf_singleton(1);
		// printf("%25s %6d %10s %6c\n", "pf_parse_flag", pf->i, "lettre", format[pf->i]);
	if ((format[pf->i] == '#') && (pf->arg.diez = 1))
		return (1);
	if ((format[pf->i] == '0') && (pf->arg.zero = 1))
		return (1);
	if ((format[pf->i] == '+') && (pf->arg.more = 1))
		return (1);
	if ((format[pf->i] == '-') && (pf->arg.less = 1))
		return (1);
	if ((format[pf->i] == ' ') && (pf->arg.space = 1))
		return (1);
	// if ((format[pf->i] == '{') && (pf->arg.col = 1))
	// 	return (1);
	return (1);
}

static int		pf_parse_width(const char *restrict format)
{
	t_printf	*pf;
	int			start;

	pf = pf_singleton(1);
	if (format[pf->i] && format[pf->i] == '*' && (pf->arg.width = -1))
	{
		// printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", format[pf->i]);
		// printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
		return (1);
	}
	start = pf->i;
	while (format[pf->i])
	{
		// printf("%25s %6d %10s %6c\n", "pf_parse_width", pf->i, "lettre", format[pf->i]);
		if ((int)format[pf->i] < '0' || (int)format[pf->i] > '9')
			break;
		pf->i++;
	}
	if (pf->i - start > 0)
		if (!(pf->join = ft_strsub(format, start, (pf->i - start)))
		&& (pf->ret = 1))
			return (0);
		pf->arg.width = ft_atoi(pf->join);
		ft_strdel(&pf->join);
		// printf("%25s %6d %10s %6d\n", "pf_parse_width", pf->i, "width", pf->arg.width);
	return (1);
}

static void		pf_parse_specifier_init(int (**spe)(const char *restrict))
{
	spe['%'] = &pf_parse_modulo;
	spe['s'] = &pf_fake;
	spe['S'] = &pf_fake;
	spe['p'] = &pf_fake;
	spe['d'] = &pf_fake;
	spe['D'] = &pf_fake;
	spe['i'] = &pf_fake;
	spe['o'] = &pf_fake;
	spe['O'] = &pf_fake;
	spe['u'] = &pf_fake;
	spe['U'] = &pf_fake;
	spe['x'] = &pf_fake;
	spe['X'] = &pf_fake;
	spe['c'] = &pf_fake;
	spe['C'] = &pf_fake;
	// spe['{'] = &pf_parse_flag;
	spe['#'] = &pf_parse_flag;
	spe['0'] = &pf_parse_flag;
	spe['+'] = &pf_parse_flag;
	spe['-'] = &pf_parse_flag;
	spe[' '] = &pf_parse_flag;

	spe['*'] = &pf_parse_width;
	// int i = -1;
	// while (++i < 128)
	// 	if (spe[i])
			// printf("%d\n", i);
}

static int		pf_parse_specifier(const char *restrict format)
{
	static int		(*spe[128])(const char *restrict) = {NULL};
	t_printf		*pf;

	if (!spe['%'])
		pf_parse_specifier_init(spe);
	pf = pf_singleton(1);
	while (format[pf->i])
	{
		// printf("%25s %6d %10s %6c\n", "pf_parse_specifier", pf->i, "lettre", format[pf->i]);
		if ((int)format[pf->i] > '0' && (int)format[pf->i] < 58
			&& !(pf_parse_width(format)))
			break;
		else if (spe[(int)(format[pf->i])]
			&& !(spe[(int)(format[pf->i])](format)))
		{
		// printf("%25s %6d %10s %6c\n", "fin de specifier", pf->i, "lettre", format[pf->i]);
			break;
		}
		pf->i++;
	}
	if (pf->ret || (!pf->ret && pf_join(2, format)))
		return (1);
	pf->start = pf->i + 1;
	return (0);
}

int				pf_parse(const char *restrict format)
{
	t_printf	*pf;

	pf = pf_singleton(1);
	while (format[++pf->i])
	{
		// printf("%25s %6d %10s %6c\n", "pf_parse", pf->i, "lettre", format[pf->i]);
		if ((format[pf->i] == '%') && (pf_join(1, format)
		|| pf_parse_specifier(format)))
			return (1);
		// pf->i++;
	}
	if ((pf->i - pf->start) > 0 && pf_join(1, format))
		return (1);
	if (pf_join(2, format))
		return (1);
	// char		*tmp;
	// tmp = va_arg(pf->ap, char *);
	// printf("\npf->ap %s\n", tmp);
	return (0);
}
