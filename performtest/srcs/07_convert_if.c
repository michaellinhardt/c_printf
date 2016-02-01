/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:23:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/30 22:47:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perftest.h"

void        pt_get_handler07(char c, char **str)
{
    if ((int)c == (int)'%')
        pt_07_handle_escape(str);
    if ((int)c == (int)'s')
        pt_07_handle_str(str);
    if ((int)c == (int)'S')
        pt_07_handle_wstr(str);
    if ((int)c == (int)'p')
        pt_07_handle_ptr(str);
    if ((int)c == (int)'d')
        pt_07_handle_int(str);
    if ((int)c == (int)'D')
        pt_07_handle_long(str);
    if ((int)c == (int)'i')
        pt_07_handle_int(str);
    if ((int)c == (int)'o')
        pt_07_handle_octal(str);
    if ((int)c == (int)'O')
        pt_07_handle_long(str);
    if ((int)c == (int)'u')
        pt_07_handle_unsigned(str);
    if ((int)c == (int)'U')
        pt_07_handle_long(str);
    if ((int)c == (int)'x')
        pt_07_handle_hex(str);
    if ((int)c == (int)'X')
        pt_07_handle_hex(str);
    if ((int)c == (int)'c')
        pt_07_handle_char(str);
    if ((int)c == (int)'C')
        pt_07_handle_wchar(str);
    if ((int)c == (int)'b')
        pt_07_handle_binary(str);
    if ((int)c == (int)'f')
        pt_07_handle_float(str);
    if ((int)c == (int)'n')
        pt_07_handle_charswritten(str);
}

void        pt_07_handle_escape(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("modulo");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_str(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("str");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_wstr(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("wstr");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_ptr(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("ptr");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_long(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("long");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_int(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("int");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_octal(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("octal");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_unsigned(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("unsigned");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_hex(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("hex");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_char(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("char");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_wchar(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("wchar");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_binary(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("binary");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_float(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("float");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
void        pt_07_handle_charswritten(char **str)
{
    char    *t;
    char    *t2;

    t = *str;
    t2 = ft_strdup("charswritten");
    *str = ft_strjoin(t, t2);
    ft_strdel(&t);
    ft_strdel(&t2);
}
