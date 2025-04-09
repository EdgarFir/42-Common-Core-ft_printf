NAME = ft_printf_tester

PROJECT_DIR = ..

SRCS = test_m.c

OBJS = ${SRCS:.c=.o}

INCLUDES = -I ${PROJECT_DIR}/. -I ${PROJECT_DIR}/libft

LIBFTPRINTF = ${PROJECT_DIR}/printf/libftprintf.a

LIBFT = -L ${PROJECT_DIR}/printf/libft/ -lft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C ${PROJECT_DIR}/printf/
	${CC} ${CFLAGS} ${OBJS} ${LIBFTPRINTF} ${LIBFT} ${INCLUDES} -o ${NAME}

all: ${NAME}

clean:
	make -C ../printf/ clean
	${RM} ${OBJS}

fclean: clean
	make -C ../printf/ fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re