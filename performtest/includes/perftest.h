/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 07:21:03 by mlinhard         ###   ########.fr       */
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

//					04_03_ONLY_IF
void		pt_test_one_putstr04(void);
void		pt_parse_one_putstr04(void);
void		pt_parse_option_only_if(t_convert *conv);

#endif
