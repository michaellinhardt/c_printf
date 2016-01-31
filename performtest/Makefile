# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 03:05:25 by mlinhard          #+#    #+#              #
#    Updated: 2016/01/31 03:47:01 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	perftest
FLAGS	=	-Wall -Wextra -Werror -g
FLAGS2	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			funcs.c \
			01_only_putchar.c \
			02_multiple_putstr.c \
			03_one_putstr.c \
			04_03_only_if.c \
			05_03_only_if.c \

HDIR 	=	./includes/
LDIR 	= 	./libft/
SRCSDIR = 	./srcs/
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

RE			= \033[0;31m
GR			= \033[0;32m
YE			= \033[0;33m
BL			= \033[0;34m
WH			= \033[0;38m
OK			= $(WH)* [ $(GR)OK $(WH)]
KO			= $(WH)* [ $(RE)KO $(WH)]
W8			= $(WH)* [ $(BL)W8 $(WH)]

all: $(NAME)

$(NAME):
	@echo "$(W8) $(YE)make -C $(LDIR)$(WH)"
	@make -C $(LDIR)
	@echo "$(W8) $(YE)gcc $(FLAGS2) (SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft$(WH)"
	@gcc $(FLAGS2) $(SRC) -o $(NAME) -I$(HDIR) -I./ -L$(LDIR) -lft
	@echo "$(OK) $(GR)Done!$(WH)"

clean:
	#@echo "$(W8) $(YE)make clean -C $(LDIR)$(WH)"
	#@make clean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
	#@echo "$(W8) $(YE)make fclean -C $(LDIR)$(WH)"
	#@make fclean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf ./last.valgrind$(WH)"
	@/bin/rm -rf ./last.valgrind
	@echo "$(W8) $(YE)/bin/rm -rf ./$(NAME).dSYM$(WH)"
	@/bin/rm -rf ./$(NAME).dSYM
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

test: re
	@echo "$(W8) $(YE)time ./$(NAME) 4 | /bin/cat -e$(WH)"
	@time ./$(NAME) 4 | /bin/cat -e
	@echo "$(OK) $(GR)Done!$(WH)"

test1: re
	@echo "$(W8) $(YE)time ./$(NAME) 1$(WH)"
	@time ./$(NAME) 1
	@echo "$(OK) $(GR)Done!$(WH)"

test2: re
	@echo "$(W8) $(YE)time ./$(NAME) 2$(WH)"
	@time ./$(NAME) 2
	@echo "$(OK) $(GR)Done!$(WH)"

test3: re
	@echo "$(W8) $(YE)time ./$(NAME) 3$(WH)"
	@time ./$(NAME) 3
	@echo "$(OK) $(GR)Done!$(WH)"

test4: re
	@echo "$(W8) $(YE)time ./$(NAME) 4$(WH)"
	@time ./$(NAME) 4
	@echo "$(OK) $(GR)Done!$(WH)"

test5: re
	@echo "$(W8) $(YE)time ./$(NAME) 5$(WH)"
	@time ./$(NAME) 5
	@echo "$(OK) $(GR)Done!$(WH)"

leaks: re -leaks
-leaks:
	@echo "$(W8) $(YE)valgrind --leak-check=yes --track-origins=yes ./$(NAME) 4 > ./last.valgrind 2>&1$(WH)"
	@valgrind --leak-check=yes --track-origins=yes ./$(NAME) 4 > ./last.valgrind 2>&1
	@echo "$(W8) $(YE)/bin/cat ./last.valgrind$(WH)"
	@/bin/cat ./last.valgrind
	@echo "$(OK) $(GR)Done!$(WH)"

.PHONY: all clean fclean re test leaks
