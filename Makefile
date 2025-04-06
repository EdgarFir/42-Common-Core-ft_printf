NAME = libftprintf.a

SRCS = ft_printf.c

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
	ar rcs ${NAME} ${OBJS} ${LIBFT_PATH}${LIBFT}

all: ${NAME}

clean:
	make -C ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	make -C ${LIBFT_PATH} fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re