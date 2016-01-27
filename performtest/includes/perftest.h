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
# include "libft.h"

# define V 1 // verbose mode

// 					MAIN.C
void		pt_run(char *argv);
void		pt_set_data(void);
void		pt_init_stats(void);
void		pt_set_route(int test);
void		pt_free_data(void);

//					DISPLAY.C
void		pt_title(char *title);

//					PARSE.C
void		pt_parse_only_putchar(void);

//					01_TEST_ONLY_PUTCHAR
void	pt_test_only_putchar(void);
//					02_TEST_MULTIPLE_PUTSTR
void	pt_test_multiple_putstr(void)

typedef struct			s_data
{
	int		again;
	int		*i;
	char	**s;
	char	*input;

	int		write;
	int		malloc;
	int		putnbr;
	int		atoi;
	int		putchar;
}						t_data;

t_data	*d;

#endif
