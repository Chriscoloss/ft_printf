# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:29:45 by chorst            #+#    #+#              #
#    Updated: 2024/04/26 13:17:00 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar -rcs

R := \033[0;31m
G := \033[0;32m
Y := \033[0;93m
D := \033[0m

SRC	= ft_printf_d_i.c ft_printf_s.c ft_printf_u.c ft_printf_x_low.c \
		ft_printf_x_up.c ft_printf_p.c ft_printf.c

all: precomp $(NAME)

$(NAME):	$(SRC:.c=.o)
	$(NAME) $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(G)$(notdir $<)$(D)\n"

clean:
	@printf "\n$(Y)(printf.o)\n$(D)"
	@for file in $(SRC:.c=.o); do \
		$(RM) $$file; \
		printf "$(R)%s\n$(D)" "$$file"; \
	done

fclean:
	@if ls *.o 1> /dev/null 2>&1; then \
		printf "$(Y)\n(libft.o)\n$(D)"; \
		for file in $(SRC:.c=.o); do \
			$(RM) $$file; \
			printf "$(R)%s\n$(D)" "$$file"; \
		done; \
		printf "$(Y)(libft.a)\n$(D)"; \
		printf "$(R)%s\n$(D)" "$(NAME)"; \
		$(RM) $(NAME); \
	elif ls $(NAME) 1> /dev/null 2>&1; then \
		printf "$(Y)\n(libft.a)\n$(D)"; \
		printf "$(R)%s\n$(D)" "$(NAME)"; \
		$(RM) $(NAME); \
	fi

re: clean all

precomp:
	@printf "$(Y)\n(printf)\n"
