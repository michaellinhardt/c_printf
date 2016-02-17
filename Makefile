# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 03:05:25 by mlinhard          #+#    #+#              #
#    Updated: 2016/02/17 06:24:14 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a
CC		=		gcc
FLAGS1	=		-Wall -Wextra -Werror -g
FLAGS2	=		-g
FLAGS3	=		-Wall -Wextra -Werror
FLAGS	=		$(FLAGS3)

SRCS	=		ft_printf.c \
				ft_printf_join.c \
				ft_printf_parse.c \
				ft_printf_parse_option.c \
				ft_printf_build_format.c \
				ft_printf_build_tools.c \
				ft_printf_build_str.c \
				ft_printf_build_int.c \
				ft_printf_build_int_tools.c

SRCS_LIB		= ft_strlen.c ft_strcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
				  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				  ft_strstr.c ft_strnstr.c ft_strncmp.c ft_putendl.c ft_itoa.c \
				  ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c \
				  ft_putnbr_fd.c ft_putnbr.c ft_stralloc.c ft_putendl_fd.c \
				  ft_islower.c ft_isupper.c ft_toupper.c ft_tolower.c \
				  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_lstmap.c \
				  ft_isprint.c ft_isspace.c ft_strdel.c ft_strclr.c ft_striter.c \
				  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
				  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c \
				  ft_atoi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
				  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
				  ft_strtolower.c ft_strtoupper.c ft_countwords.c ft_pow.c ft_strrev.c \
				  ft_pcol.c ft_imaxtoa_base.c ft_uimaxtoa_base.c ft_wstrtostr.c \
				  ft_wchartostr.c

HDIR		=	./includes/
LDIR		=	./libft/
SRCSDIR		=	./srcs/

OBJS			=	$(subst .c,.o,$(SRCS))
OBJS_LIB		=	$(subst .c,.o,$(SRCS_LIB))
LIST_OBJ		=	$(addprefix $(SRCSDIR), $(OBJS))
LIST_OBJ_LIB	=	$(addprefix $(LDIR), $(OBJS_LIB))

RE			= \033[0;31m
GR			= \033[0;32m
YE			= \033[0;33m
BL			= \033[0;34m
WH			= \033[0;38m
OK			= $(WH)* [ $(GR)OK $(WH)]
KO			= $(WH)* [ $(RE)KO $(WH)]
W8			= $(WH)* [ $(BL)W8 $(WH)]

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HDIR) -I./ -c -o $@ $<

$(NAME): $(LIST_OBJ) $(LIST_OBJ_LIB)
	ar rc $(NAME) $(LIST_OBJ) $(LIST_OBJ_LIB)
	ranlib $(NAME)

# $(NAME):
# 	@echo "$(W8) $(YE)make -C $(LDIR)$(WH)"
# 	@make -C $(LDIR)
# 	@echo "$(W8) $(YE)gcc $(FLAGS) (SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft$(WH)"
# 	@gcc $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -I./ -L$(LDIR) -lft
# 	@echo "$(OK) $(GR)Done!$(WH)"

clean:
	#@echo "$(W8) $(YE)make clean -C $(LDIR)$(WH)"
	#@make clean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(LIST_OBJ) $(LIST_OBJ_LIB)$(WH)"
	@/bin/rm -rf $(LIST_OBJ) $(LIST_OBJ_LIB)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
	#@echo "$(W8) $(YE)make fclean -C $(LDIR)$(WH)"
	#@make fclean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(W8) $(YE)/bin/rm -rf ./last.valgrind$(WH)"
	@/bin/rm -rf ./last.valgrind
	@echo "$(W8) $(YE)/bin/rm -rf ./*.dSYM$(WH)"
	@/bin/rm -rf ./*.dSYM
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

-main-clean:
	@echo "$(W8) $(YE)/bin/rm -rf a.out$(WH)"
	@/bin/rm -rf a.out

-main:
	@echo "$(W8) $(YE)/bin/rm -rf a.out$(WH)"
	@/bin/rm -rf a.out
	@echo "$(W8) $(YE)/bin/rm -rf main.o$(WH)"
	@/bin/rm -rf main.o
	@echo "$(W8) $(YE)$(CC) $(FLAGS) main.c -I$(HDIR) -L./ -lftprintf$(WH)"
	@$(CC) $(FLAGS) main.c -I$(HDIR) -I./ -L./ -lftprintf
	@echo "$(W8) $(YE)/bin/rm -rf main.o$(WH)"
	@/bin/rm -rf main.o
	@echo "$(OK) $(GR)Done!$(WH)"

test: all -main -test -main-clean
-test:
	@echo "$(W8) $(YE)time ./a.out | /bin/cat -e$(WH)"
	@time ./a.out | /bin/cat -e
	@echo "$(OK) $(GR)Done!$(WH)"

leaks: all -main -leaks -main-clean
-leaks:
	@echo "$(W8) $(YE)valgrind --leak-check=yes --track-origins=yes ./a.out > ./last.valgrind 2>&1$(WH)"
	@valgrind --leak-check=yes --track-origins=yes ./a.out > ./last.valgrind 2>&1
	@echo "$(W8) $(YE)/bin/cat ./last.valgrind$(WH)"
	@/bin/cat ./last.valgrind
	@echo "$(OK) $(GR)Done!$(WH)"

.PHONY: all clean fclean re test leaks -leaks -main
