NAME = push_swap
S_DIR = srcs srcs/moves srcs/tri srcs/ft_utils
SRCS = $(foreach dir, ${S_DIR}, ${wildcard $(dir)/*.c})
OBJS = ${SRCS:.c=.o}

BONUS_NAME = checker
S_DIR_BONUS = srcs/bonus srcs/moves srcs/ft_utils
BONUS_SRCS = $(foreach dir, ${S_DIR_BONUS}, ${wildcard $(dir)/*.c}) srcs/parse.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

H_DIR = includes
LFT = lib/libft
LIBFLAGS = -Llib/libft -lft
FLAGS = -Wall -Wextra -Werror -I ${H_DIR}


.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LFT}
	gcc ${FLAGS} ${LIBFLAGS} ${OBJS} -o ${NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	make -C ${LFT}
	gcc ${FLAGS} ${LIBFLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

all: ${NAME}

clean:
	make clean -C ${LFT}
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean: clean
	make fclean -C ${LFT}
	rm -f ${NAME}
	rm -f ${BONUS_NAME}

re: fclean ${NAME}

bonus: ${BONUS_NAME}

.PHONY: all, clean, fclean, re, bonus