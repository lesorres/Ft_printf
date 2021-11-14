# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 21:06:31 by kmeeseek          #+#    #+#              #
#    Updated: 2021/01/30 03:17:10 by kmeeseek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCL = ./

INPUT = ft_printf.c ft_parser.c ft_basic_functions_one.c \
ft_basic_functions_two.c ft_print_i_d.c ft_print_u.c ft_print_x.c \
ft_print_p.c ft_print_percent.c ft_print_c.c ft_print_s.c

OFILES = ${INPUT:.c=.o}

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	gcc -Wall -Wextra -Werror -c $< -o $@ -I $(INCL)
clean:
	rm -f $(OFILES)
fclean:	clean
	rm -f $(NAME)
re: fclean all