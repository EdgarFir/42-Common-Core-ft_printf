NAME = libftprintf.a

SRCS = ft_printf.c ft_format_s.c ft_format_c.c ft_format_p.c \
	   ft_format_x.c ft_format_u.c ft_is_valid_conv.c \
	   ft_format_i_d.c ft_print_spaces.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

RM = rm -f

.c.o:
	${CC} ${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C libft bonus
	ar rcs ${NAME} ${OBJS} libft/*.o

all: ${NAME}

clean:
	make -C libft clean
	${RM} ${OBJS}

fclean: clean
	make -C libft fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re