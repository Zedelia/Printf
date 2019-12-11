NAME = printf

INCLUDES = ft_printf

SRCS = ft_printf \
	utils/utils_1 \
	utils/utils_2 \
	utils/convert_bases \
	utils/get_indicator \
	utils/get_arg_1 \
	utils/get_arg_2 \
	utils/get_arg_init \
	utils/get_width_preci \
	apply/apply_diux \
	apply/apply_diux_tiret \
	apply/apply_diux_zero_pos \
	apply/apply_diux_zero_neg \
	apply/apply_cs \
	apply/apply_cs_tiret \
	apply/apply_cs_none \
	apply/apply_diux_arg_zero \
	apply/apply_percent \
	apply/apply_diux_zero \
	convert/convert_diu \
	convert/convert_sc \
	convert/convert_percent \
	convert/convert_x \
	convert/convert_p \
	format/format_init \
	format/format_free \
	format/format_parser \
	format/format_replace_pattern \
	patterns/pattern_init \
	patterns/pattern_free \
	patterns/pattern_parser \
	patterns/pattern_copy \
	patterns/pattern_errors_1 \
	patterns/pattern_errors_2 \
	patterns/pattern_errors_init \
	patterns/pattern_check \
	patterns/pattern_convert_init \
	flags/flag_free \
	flags/flag_init \
	flags/flag_parser \
	flags/flag_width \
	flags/flag_precision \
	tests/tests_struct \
	tests/tests_show_vargs \
	tests/tests_utils

# get_hidden_obj = $(addprefix ., $(notdir $(1)))
# hidden_format = $(addprefix $(dir $(1)), $(call get_hidden_obj, $(1)))
# convert_src = $(strip $(call hidden_format, $(1:%.c=%.o)))

LIB = libft/libft.a
LIB_PRINTF = lib_printf.a

INCLUDES := $(patsubst %,includes/%.h,${INCLUDES})
SRCS := $(patsubst %,srcs/%.c,${SRCS})

# OBJ := $(foreach file, $(SRCS:%.c=%.o), $(call hidden_format, $(file)))

MAIN = main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
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

test_p: ${OBJ} ${LIB}
		 ${COMP} -o test ${OBJ} ${LIB} tests_p.c

cf : ${OBJ} ${MAIN} ${LIB}
	 ${COMPf} -o ${NAME} ${OBJ} ${LIB} ${MAIN}

lib : ${OBJ}
	ar rc $(LIB_PRINTF) ${OBJ} libft/srcs/*.o
	ranlib $(LIB_PRINTF)

$(LIB):
	make bonus -C libft


clean:
	make clean -C libft
	rm -f includes/*.gch
	rm -f ${OBJ}

clean_test:
	rm -R *.dSYM
	rm -f test_* one two

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
