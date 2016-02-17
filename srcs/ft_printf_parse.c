/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:12:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/02/17 06:20:20 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pf_parse_modulo(t_printf *pf)
{
	(void)pf->in;
	if (!pf->arg.modulo && (pf->arg.modulo = 1))
		return (1);
	if (pf_build_modulo(pf))
		pf->ret = 1;
	return (0);
}

static void		pf_parse_specifier_init(int (**spe)(t_printf *))
{
	spe['%'] = &pf_parse_modulo;
	spe['s'] = &pf_build_string;
	spe['c'] = &pf_build_char;
	spe['S'] = &pf_build_wstring;
	spe['C'] = &pf_build_wchar;
	spe['i'] = &pf_build_int;
	spe['d'] = &pf_build_int;
	spe['D'] = &pf_build_int;
	spe['u'] = &pf_build_uint;
	spe['U'] = &pf_build_uint;
	spe['o'] = &pf_build_oint;
	spe['O'] = &pf_build_oint;
	spe['x'] = &pf_build_xint;
	spe['X'] = &pf_build_xint;
	spe['p'] = &pf_build_ptr;
	// spe['{'] = &pf_parse_flag;
	spe['#'] = &pf_parse_flag;
	spe['0'] = &pf_parse_flag;
	spe['+'] = &pf_parse_flag;
	spe['-'] = &pf_parse_flag;
	spe[' '] = &pf_parse_flag;

	spe['*'] = &pf_parse_width;
	spe['.'] = &pf_parse_preci;

	spe['h'] = &pf_parse_length;
	spe['l'] = &pf_parse_length;
	spe['j'] = &pf_parse_length;
	spe['z'] = &pf_parse_length;

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
			break;
		}
		else if (((int)pf->in[pf->i] < '0' || (int)pf->in[pf->i] > 57)
		&& (!spe[(int)(pf->in[pf->i])]))
		{
			break;
		}
		else if (pf->in[pf->i] && spe[(int)(pf->in[pf->i])]
			&& !(spe[(int)(pf->in[pf->i])](pf)))
		{
			break;
		}
		pf->i++;
	}
	if (pf->valid == 0 && !pf->ret && pf_build_invalid(pf))
		return (1);
	if (pf->ret || (!pf->ret && pf_join(pf, 2)))
		return (1);
	pf->start = pf->i + 1;
	ft_bzero((void *)&pf->arg, sizeof(t_arg));
	return (0);
}

int				pf_parse(t_printf *pf)
{

	while (pf->in[pf->i])
	{
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
