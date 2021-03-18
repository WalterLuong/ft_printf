# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wluong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/07 09:43:12 by wluong            #+#    #+#              #
#    Updated: 2020/11/12 01:11:10 by wluong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRC		=	ft_bzero.c \
	 		ft_memalloc.c \
	 		ft_strlen.c \
	 		ft_isdigit.c \
	 		ft_atoi.c \
	 		ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_itoa_base.c \
			ft_putwstr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all