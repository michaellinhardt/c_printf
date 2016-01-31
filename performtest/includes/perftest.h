/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/31 20:49:20 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERFTEST_H
# define PERFTEST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define V 1 // verbose mode

typedef struct			s_data
{
	int		again;
	int		*i;
	char	**s;
	char	*input;
	char	*input2;
	char	*input3;
}						t_data;

typedef struct			s_convert
{
	char	specifier;

	int		flags_less;
	int		flags_more;
	int		flags_space;
	int		flags_diez;
	int		flags_zero;
	int		id;
	int		i;
}						t_convert;

t_data	*d;

// 					MAIN.C
void		pt_run(char *argv);
void		pt_set_data(void);
void		pt_init_stats(void);
void		pt_set_route(int test);
void		pt_free_data(void);

//					FUNCS.C
void		pt_title(char *title);
void		pt_option_reset(t_convert *conv);
void		pt_join_conv(t_convert *conv, char **str);

//					01_TEST_ONLY_PUTCHAR
void		pt_test_only_putchar(void);
void		pt_parse_only_putchar(void);

//					02_TEST_MULTIPLE_PUTSTR
void		pt_test_multiple_putstr(void);
void		pt_parse_multiple_putstr(void);

//					03_TEST_ONE_PUTSTR
void		pt_test_one_putstr(void);
void		pt_parse_one_putstr(void);

//					04_03_ONLY_IF && FT_MEMALLOC
void		pt_test_one_putstr04(void);
void		pt_parse_one_putstr04(void);
void		pt_parse_option_only_if(t_convert *conv);

//					05_03_ONLY_IF && MALLOC
void		pt_test_one_putstr05(void);
void		pt_parse_one_putstr05(void);
void		pt_parse_option_only_if05(t_convert *conv);

//					06_TAB_POINTEUR
void	pt_test_one_putstr_tab_pointeur(void);
void	pt_parse_one_putstr_tab_pointeur(void);
void	pt_get_handler06(char c, char **str);
void		pt_06_handle_escape(char **str);
void		pt_06_handle_str(char **str);
void		pt_06_handle_wstr(char **str);
void		pt_06_handle_ptr(char **str);
void		pt_06_handle_int(char **str);
void		pt_06_handle_octal(char **str);
void		pt_06_handle_long(char **str);
void		pt_06_handle_unsigned(char **str);
void		pt_06_handle_hex(char **str);
void		pt_06_handle_char(char **str);
void		pt_06_handle_wchar(char **str);
void		pt_06_handle_binary(char **str);
void		pt_06_handle_float(char **str);
void		pt_06_handle_charswritten(char **str);

#endif
