NAME = s21_sp
SRCS = s21vers2.c
SRCV = s21vers2.o


CC		= gcc
RM		= rm -f

FLAGS =  -Wall -Wextra -Werror 

all: 
	make s21vers2

s21vers2:
		${CC} -o ${NAME} ${FLAGS} ${SRCS} -lm

test:
		sh testbljat.sh

clean:
		${RM} ${SRCV}
		${RM} ${NAME}

rebuild:		fclean all

