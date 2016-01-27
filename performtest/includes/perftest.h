/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/27 03:58:33 by mlinhard         ###   ########.fr       */
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
void		pt_free_data(void);
void		pt_set_route(int test);

void	pt_test_only_write(void);

typedef struct			s_data
{
	int		*i;
	char	**s;
}						t_data;

t_data	*d;

#endif
