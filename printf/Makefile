# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:57:14 by edfreder          #+#    #+#              #
#    Updated: 2025/04/15 15:57:14 by edfreder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_format_s.c ft_format_c.c ft_format_p.c \
	   ft_format_x.c ft_format_u.c ft_is_valid_conv.c \
	   ft_format_i_d.c ft_putnbr_base.c ft_putstr.c ft_strchr.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

RM = rm -f

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
