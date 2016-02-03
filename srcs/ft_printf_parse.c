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
	printf("call pf_fake");
	pf = pf_singleton(1);

	return (1);
}

static int		pf_parse_flag(const char *restrict format)
{
	t_printf		*pf;
	printf("parse flag\n");

	pf = pf_singleton(1);
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

static void		pf_parse_specifier_init(int (**spe)(const char *restrict))
{

	// sSpdDioOuUxXcC%
	// flags #0-+ et espace
	// la taille minimum du champ
	// la précision
	// lesflags h hh l ll j z
	// conversions plus délicates : eE, fF, gG, aA, n
	//  flags plus delicats : *, $, L, ’ .
	//  %b binaire
	//  %r pour afficher une chaine avec des caractères non imprimables
	//  %k pour afficher une date à un format ISO quelconque
	spe['%'] = &pf_fake;
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
	// int i = -1;
	// while (++i < 128)
	// 	if (spe[i])
	// 		printf("%d\n", i);
}

static int		pf_parse_specifier(const char *restrict format)
{
	static int		(*spe[128])(const char *restrict) = {NULL};
	t_printf		*pf;

	if (!spe['%'])
		pf_parse_specifier_init(spe);
	pf = pf_singleton(1);
	while (format[pf->i] && spe[(int)(format[pf->i])]
	&& spe[(int)(format[pf->i])](format))
		pf->i++;
	if (pf->ret || (!pf->ret && pf_join(2, format)))
		return (1);
	pf->start = pf->i;
	return (0);
}

int				pf_parse(const char *restrict format)
{
	t_printf	*pf;

	pf = pf_singleton(1);
	while (format[pf->i++])
	{
		if ((format[pf->i] == '%') && (pf_join(1, format)
		|| pf_parse_specifier(format)))
			return (1);
	}
	if ((pf->i - pf->start) > 0 && pf_join(1, format))
		return (-1);
	// char		*tmp;
	// tmp = va_arg(pf->ap, char *);
	// printf("\npf->ap %s\n", tmp);
	return (0);
}
