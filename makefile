NAME = printf

INCLUDES = ft_printf

SRCS = ft_printf \
	format_init \
	format_free \
	format_parser \
	pattern_init \
	pattern_free \
	pattern_parser \
	utils \
	get_arg \
	convert_bases \
	tests_struct \
	tests_show_vargs \
	flag_free \
	flag_init \
	flag_parser \
	get_indicator \
	flag_width \
	pattern_check \
	tests_utils \
	pattern_copy \
	pattern_errors_1 \
	pattern_errors_2 \
	pattern_errors_init

LIB = libft/libft.a

INCLUDES := $(patsubst %,includes/%.h,${INCLUDES})
SRCS := $(patsubst %,srcs/%.c,${SRCS})

MAIN = main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DFLAGS =
COMP =${CC} -g -fsanitize=address -I ${INCLUDES}
COMPf := ${CC} ${CFLAGS} -I ${INCLUDES}

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m
_PURPLE = \x1b[35m

OBJ := ${SRCS:.c=.o}

all : ${OBJ} ${NAME}
		@echo "$(OK_COLOR)\n>> Congrats. Your program $(NAME) has been\
 created successfully.\n $(NO_COLOR)"

${NAME}: ${OBJ} ${MAIN} ${LIB}
		 ${COMP} -o ${NAME} ${OBJ} ${LIB} ${MAIN}

cf : ${OBJ} ${MAIN} ${LIB}
	 ${COMPf} -o ${NAME} ${OBJ} ${LIB} ${MAIN}


$(LIB):
	make bonus -C libft

clean:
	make clean -C libft
	rm -f ${OBJ}

run: ./${NAME}
	./${NAME} ${ARGS}

fclean: clean
	make fclean -C libft
	rm -f ${NAME} gnl.a Icon srcs/Icon srcs/get_next_line.h.gch
	@echo "$(_PURPLE)\n>> Folders cleaned.\n $(NO_COLOR)"


norm:
	norminette ${SRCS} ${INCLUDES}

re: fclean all


.PHONY: norm all re fclean clean progs bonus
