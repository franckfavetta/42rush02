
NAME = rush-02

SRCS = src/main.c src/funcs.c src/rush02.c

OBJS = ${SRC:.c=.o}

FLAGS = -g3 -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
