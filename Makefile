NAME = libftprintf.a

SRCS = ft_printf.c ft_format_s.c ft_format_c.c ft_format_p.c \
	   ft_format_xX.c ft_format_u.c ft_hexlen.c ft_is_valid_conv.c ft_ulen.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

RM = rm -f

LIBFT = libft.a

LIBFT_PATH = libft/

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C ${LIBFT_PATH} bonus
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	make -C ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	make -C ${LIBFT_PATH} fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re