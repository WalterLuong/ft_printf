# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wluong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 00:40:27 by wluong            #+#    #+#              #
#    Updated: 2020/11/12 01:50:58 by wluong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
LIB			= Libft
LIBFT 		= libft.a
SRC 		=	srcs/check_error.c \
				srcs/convert_type.c \
				srcs/ft_printf_char.c \
				srcs/ft_printf_int.c \
				srcs/ft_printf_percent.c \
				srcs/ft_printf_pointer.c \
				srcs/ft_printf_str.c \
				srcs/ft_printf_unsigned.c \
				srcs/ft_printf_width.c \
				srcs/ft_printf_x.c \
				srcs/ft_printf_xx.c \
				srcs/ft_printf.c \
				srcs/initialize.c \
				srcs/parsing.c

SRCS_O		=	check_error.o \
				convert_type.o \
				ft_printf_char.o \
				ft_printf_int.o \
				ft_printf_percent.o \
				ft_printf_pointer.o \
				ft_printf_str.o \
				ft_printf_unsigned.o \
				ft_printf_width.o \
				ft_printf_x.o \
				ft_printf_xx.o \
				ft_printf.o \
				initialize.o \
				parsing.o \
				
INCLUDE 	= -I./includes

OBJS 		= $(SRC:.c=.o)

AR 			= ar rcs
RM 			= rm -f	
CC 			= gcc
FLAGS 		= -Wall -Werror -Wextra

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIB)
			cp $(LIB)/$(LIBFT) $(NAME)
			$(AR) $(NAME) $(OBJS)

bonus:		$(NAME)

clean:		
			$(RM) $(OBJS)
			$(RM) $(SRCS_O)
			make clean -C $(LIB)
			
fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIB)

re:			fclean all

	


