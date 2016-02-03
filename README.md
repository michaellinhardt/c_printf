# LIBPF.A
## printf partial re-implementation
- Langage: C
- 42 school project, docs/printf.pdf
- Date: jan. 2016

## repo map
| repo path | description |
| ------------- | ------------- |
| docs/printf.pdf	 | french details of project	 |
| includes/			 | headers location						 |
| libft/				 | libft.a project <a href="https://github.com/nesthub/c_libft" target="_blank">here</a>	 |
| srcs/				 | .c sources							 |
| auteur				 | 42 requierement: author's login	 |

## man, namespace: p(rint)f_(function name);
### data
- almost all var are stored in one struct s_printf (t_printf)
- t_printf is static in pf_singleton(int), not malloc'd
- pf_singleton(int last), 0 to reset all iterator before return
- pf_join(int from, char *format), join to pf->join a new str
- if int from=1 join with ft_strsub(format, pf->start, pf->i);
- if int from=2 join with spe[x]()
- x is the specifier letter: (int)(char format[pf->i])
- spe[x] is ptr to addr function for the specifier x (see below)
- pf_return(int ret), free pf->join before return

### parsing
- pf_parse read format, when meet '%':
- it call pf_join to add previous input to pf->join
- pf_parse call pf_parse_specifier
- pf_parse_specifier have static struct t_spe spe[];
- pf_parse_specifier call spe[x]() who write in t_printf
- then call pf_join who use t_printf to add it in pf->join

### pf_join method
- #1: 's' = ft_strjoin(char *pf->join, char *formated);
- d:

### location
| file | function |
| ------------- | ------------- |
| ft_printf.c | ft_printf |
| ft_printf.c | pf_return |
|   |   |
| ft_printf_singleton.c | pf_singleton |
|   |   |
| ft_printf_parse.c | pf_return |
| ft_printf_parse.c | pf_parse |
|   |   |
| ft_printf_join.c | pf_join |
