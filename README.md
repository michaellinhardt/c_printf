# Printf re-implementation, libpf.a
- Langage: C
- Subject: 42 school project, re-implementation of printf (see docs/printf.pdf for details)
- Date: jan. 2016

## repo map
| repo path | description |
| ------------- | ------------- |
| docs/printf.pdf	 | french details of project	 |
| includes/			 | headers location						 |
| libft/				 | libft.a project <a href="https://github.com/nesthub/c_libft" target="_blank">here</a>	 |
| srcs/				 | .c sources							 |
| auteur				 | 42 requierement: author's login	 |

## libpf, namespace: p(rint)f_(function name);
### data functions
- almost all var are stored in one struct (t_printf)
- t_printf is static from pf_singleton(int), not malloc'd
- pf_singleton(int last), 0 to reset all iterator before return
- pf_join(int from, char *format), join to pf->join a new str
- if int from=1 join with ft_strsub(format, pf->start, pf->i);
- if int from=2 join with specifier[x]();
- x is the specifier letter: (int)(char format[pf->i])
- specifier[x] is ptr to addr function for the specifier x
- pf_return(int ret), free pf->join before return

### specifier functions
- s: ft_strjoin(char *pf->join, char *formated);
- d:

ft_printf.c
	int		ft_printf(format, ...); (use pf_singleton *)
	  * set pf ptr to struct addr return from pf_singleton (all var here)
		set pf->join ptr to ft_strnew(0) (prevent memory UB)
	t_printf	*pf;

	if (!(pf = pf_singleton(0)) || !(pf->join = ft_strnew(0)))
		return (pf_return(-1));
	va_start(pf->ap, format);
	if (pf_parse(format))
		return (pf_return(-1));



	int		pf_return(ret);
ft_printf_singleton.c
	t_printf	*pf_singleton(last);
ft_printf_parse.c
int			pf_parse(format);
ft_printf_join.c
int			pf_join(method, format);
