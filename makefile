NAME = printf

NAME_TEST = tests

INCLUDES = ft_printf

SRCS = printf/ft_printf \
	printf/put_output \
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
	apply/apply_sc_create_str \
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
	inputs/input_init \
	inputs/input_free \
	inputs/input_parser \
	inputs/input_cpy \
	inputs/input_indicator \
	inputs/input_convert \
	flags/flag_free \
	flags/flag_init \
	flags/flag_parser \
	flags/flag_width \
	flags/flag_preci \
	utils/tests_utils

TESTS =	tests/tests_struct \
	tests/tests_show_vargs \

# get_hidden_obj = $(addprefix ., $(notdir $(1)))
# hidden_format = $(addprefix $(dir $(1)), $(call get_hidden_obj, $(1)))
# convert_src = $(strip $(call hidden_format, $(1:%.c=%.o)))

LIB = libft/libft.a
LIB_PRINTF = libftprintf.a

INCLUDES := $(patsubst %,includes/%.h,${INCLUDES})
SRCS := $(patsubst %,srcs/%.c,${SRCS})
TESTS := $(patsubst %,srcs/%.c,${TESTS})

# OBJ := $(foreach file, $(SRCS:%.c=%.o), $(call hidden_format, $(file)))

MAIN = main.c
MAIN_TEST = tests.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DFLAGS = -g -fsanitize=address
COMP =${CC} ${CFLAGS} -I ${INCLUDES}
COMPf := ${CC} ${CFLAGS} -I ${INCLUDES}

GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m
END = \x1b[0m
ERASE = \033[2K\r

OBJ := ${SRCS:.c=.o}
OBJ_TEST := ${SRCS:.c=.o} ${TESTS:.c=.o}


all : ${OBJ} $(LIB)
		@ar rc $(LIB_PRINTF) ${OBJ}
		@ranlib $(LIB_PRINTF)
		@echo "$(ERASE)$(GREEN)[SUCCESS] $(LIB_PRINTF)$(END)"

${NAME}: ${OBJ} ${MAIN} ${LIB}
		 ${COMP} -o ${NAME} ${OBJ} ${LIB} ${MAIN}

test: ${OBJ} ${MAIN_TEST} ${LIB}
		  gcc -g -o ${NAME_TEST} ${OBJ} ${LIB} ${MAIN_TEST}

test2: ${OBJ_TEST} ${MAIN_TEST} ${LIB}
		  gcc -g -o ${NAME_TEST} ${OBJ_TEST} ${LIB} tests2.c

cf : ${OBJ} ${MAIN} ${LIB}
	 ${COMPf} -o ${NAME} ${OBJ} ${LIB} ${MAIN}

lib : ${OBJ}
	ar rcs $(LIB_PRINTF) ${LIB} ${OBJ}
	ranlib $(LIB_PRINTF)

$(LIB):
	@make bonus -C libft

%.o : %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INCLUDES)  -c  -o $@ $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

clean:
	@make clean -C libft
	@rm -f includes/*.gch
	@rm -f ${OBJ}
	@printf "$(BLUE)> Deleted : $(RED)printf .obj$(END)\n"

clean_test:
	rm -R -f *.dSYM
	rm -f test_*

run: ./${NAME}
	./${NAME} ${ARGS}

fclean: clean
	@make fclean -C libft
	@rm -f $(LIB_PRINTF)
	@rm -f ${NAME} gnl.a Icon srcs/Icon
	@printf "$(BLUE)> Deleted : $(RED)libftprintf.a $(END)\n"

norm:
	norminette ${SRCS} ${INCLUDES}

re: fclean all


.PHONY: norm all re fclean clean progs bonus test