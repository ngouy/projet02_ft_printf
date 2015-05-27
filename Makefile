#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherman <stherman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:58:54 by stherman          #+#    #+#              #
#    Updated: 2014/11/11 18:07:04 by ngouy            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc
NAME		= libftprintf.a

SRC			= \
			  ft_wcharlen.c\
			  ft_apply_opt.c\
			  ft_apply_opt_aux.c\
			  ft_convert_int.c\
			  ft_found_opt_len.c\
			  ft_found_opt_len_aux1.c\
			  ft_convert_long_int.c\
			  ft_convert_unsigned_long_int.c\
			  ft_ptr.c\
			  ft_wart.c\
			  ft_printf.c\
			  ft_printf_aux1.c\
			  ft_printf_aux2.c\
			  ft_printf_aux3.c\

OBJ			= $(SRC:.c=.o)
CFLAGS		= -Wall -Werror -Wextra -ansi -pedantic
OFLAGS		= -O3
MAKE		= make -C ./libft/

RM			= rm -rf

all: $(NAME)

$(NAME):
			$(MAKE)
			gcc -I Include/ -c $(SRC)
			ar rc temp.a $(OBJ)
			libtool -static -o $(NAME) libft/libft.a temp.a
clean:
			$(RM) $(OBJ)
			$(MAKE) clean

spec : 
			gcc -I Include/ libft/libft.a $(SRC)

fclean:		clean
			$(RM) $(NAME) temp.a
			$(MAKE) fclean

re:			fclean all

norminette :
	norminette $(SRC) ./Include/header.h ./Include/libft.h

.PHONY:		all clean re fclean
