/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 04:16:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERFTEST_H
# define PERFTEST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

// 					MAIN.C
void		pt_run(char *argv);
void		pt_set_data(void);
void		pt_init_stats(void);
void		pt_set_route(int test);
void		pt_free_data(void);

//					DISPLAY.C
void		pt_title(char *title);

//					01_TEST_WRITE
void	pt_test_only_write(void);

typedef struct			s_data
{
	int		again;
	int		*i;
	char	**s;
	char	*input;

	int		write;
	int		malloc;
}						t_data;

t_data	*d;

#endif
