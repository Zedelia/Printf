#!/usr/bin/env python3

import os
import sys

UNITTEST = {
    # nom du fichier : [format , value1, value2, ... ],

    #  "simple_test": ["simple"],
    # "test_int_zero_01": ["[%0d]", 0],
	# "test_int_zero_02": ["[%0.0d]", 0],
	# "test_int_zero_03": ["[%.0d]", 0],
	# "test_int_zero_04": ["[%25d]", 0],
	# "test_int_zero_05": ["[%025.0d]", 0],
	# "test_int_zero_06": ["[%25.0d]", 0],
	# "test_int_zero_07": ["[%-25.0d]", 0],
    # "test_int_zero_08": ["[%-5.0d]", 0],
	# "test_int_zero_09": ["[%.5d]", 0],
	# "test_int_zero_10": ["[%-5.5d]", 0],
	# "test_int_zero_11": ["[%0.25d]", 0],
	# "test_int_zero_12": ["[%.25d]", 0],
	# "test_int_zero_13": ["[%-5.25d]", 0],
	# "test_int_zero_14": ["[%025.25d]", 0],
	# "test_int_zero_15": ["[%25.25d]", 0],
	# "test_int_zero_16": ["[%025.25d]", 0],
    # "test_int_zero_17": ["[%25.25d]", 0],
	# "test_int_zero_18": ["[%-25.25d]", 0],
	# "test_int_zero_19": ["[%5d]", 0],
	# "test_int_zero_20": ["[%05.0d]", 0],
	# "test_int_zero_21": ["[%5.0d]", 0],
	# "test_int_zero_22": ["[%05.5d]", 0],
	# "test_int_zero_23": ["[%5.5d]", 0],
	# "test_int_zero_24": ["[%.25d]", 0],
	# "test_int_zero_24": ["[%25d]", 0],
	# "test_int_zero_25": ["[%025d]", 0],
    # "test_int_pos_01": ["[%0d]", 2147483647],
	# "test_int_pos_02": ["[%0.0d]", 2147483647],
	# "test_int_pos_03": ["[%.0d]", 2147483647],
	# "test_int_pos_04": ["[%25d]", 2147483647],
	# "test_int_pos_05": ["[%025.0d]", 2147483647],
	# "test_int_pos_06": ["[%25.0d]", 2147483647],
	# "test_int_pos_07": ["[%-25.0d]", 2147483647],
    # "test_int_pos_08": ["[%-5.0d]", 2147483647],
	# "test_int_pos_09": ["[%.5d]", 2147483647],
	# "test_int_pos_10": ["[%-5.5d]", 2147483647],
	# "test_int_pos_11": ["[%0.25d]", 2147483647],
	# "test_int_pos_12": ["[%.25d]", 2147483647],
	# "test_int_pos_13": ["[%-5.25d]", 2147483647],
	# "test_int_pos_14": ["[%025.25d]", 2147483647],
    # "test_int_pos_15": ["[%25.25d]", 2147483647],
	# "test_int_pos_16": ["[%-25.25d]", 2147483647],
	# "test_int_pos_17": ["[%5d]", 2147483647],
	# "test_int_pos_18": ["[%05.0d]", 2147483647],
	# "test_int_pos_19": ["[%5.0d]", 2147483647],
	# "test_int_pos_20": ["[%05.5d]", 2147483647],
	# "test_int_pos_22": ["[%5.5d]", 2147483647],
	# "test_int_pos_23": ["[%.25d]", 2147483647],
	# "test_int_pos_24": ["[%25d]", 2147483647],
	# "test_int_pos_25": ["[%025d]", 2147483647],
    # "test_int_neg_01": ["[%0d]", -2147483647],
	# "test_int_neg_02": ["[%0.0d]", -2147483647],
	# "test_int_neg_03": ["[%.0d]", -2147483647],
	# "test_int_neg_04": ["[%25d]", -2147483647],
	# "test_int_neg_05": ["[%025.0d]", -2147483647],
	# "test_int_neg_06": ["[%25.0d]", -2147483647],
	# "test_int_neg_07": ["[%-25.0d]", -2147483647],
    # "test_int_neg_08": ["[%-5.0d]", -2147483647],
	# "test_int_neg_09": ["[%.5d]", -2147483647],
	# "test_int_neg_10": ["[%-5.5d]", -2147483647],
	# "test_int_neg_11": ["[%0.25d]", -2147483647],
	# "test_int_neg_12": ["[%.25d]", -2147483647],
	# "test_int_neg_13": ["[%-5.25d]", -2147483647],
	# "test_int_neg_14": ["[%025.25d]", -2147483647],
    # "test_int_neg_15": ["[%25.25d]", -2147483647],
	# "test_int_neg_16": ["[%-25.25d]", -2147483647],
	# "test_int_neg_17": ["[%5d]", -2147483647],
	# "test_int_neg_18": ["[%05.0d]", -2147483647],
	# "test_int_neg_19": ["[%5.0d]", -2147483647],
	# "test_int_neg_20": ["[%05.5d]", -2147483647],
	# "test_int_neg_22": ["[%5.5d]", -2147483647],
	# "test_int_neg_23": ["[%.25d]", -2147483647],
	# "test_int_neg_24": ["[%25d]", -2147483647],
	# "test_int_neg_25": ["[%025d]", -2147483647],
    # "test_u_neg_01": ["[%0u]", -2147483647],
	# "test_u_neg_02": ["[%0.0u]", -2147483647],
	# "test_u_neg_03": ["[%.0u]", -2147483647],
	# "test_u_neg_04": ["[%25u]", -2147483647],
	# "test_u_neg_05": ["[%025.0u]", -2147483647],
	# "test_u_neg_06": ["[%25.0u]", -2147483647],
	# "test_u_neg_07": ["[%-25.0u]", -2147483647],
    # "test_u_neg_08": ["[%-5.0u]", -2147483647],
	# "test_u_neg_09": ["[%.5u]", -2147483647],
	# "test_u_neg_10": ["[%-5.5u]", -2147483647],
	# "test_u_neg_11": ["[%0.25u]", -2147483647],
	# "test_u_neg_12": ["[%.25u]", -2147483647],
	# "test_u_neg_13": ["[%-5.25u]", -2147483647],
	# "test_u_neg_14": ["[%025.25u]", -2147483647],
    # "test_u_neg_15": ["[%25.25u]", -2147483647],
	# "test_u_neg_16": ["[%-25.25u]", -2147483647],
	# "test_u_neg_17": ["[%5u]", -2147483647],
	# "test_u_neg_18": ["[%05.0u]", -2147483647],
	# "test_u_neg_19": ["[%5.0u]", -2147483647],
	# "test_u_neg_20": ["[%05.5u]", -2147483647],
	# "test_u_neg_22": ["[%5.5u]", -2147483647],
	# "test_u_neg_23": ["[%.25u]", -2147483647],
	# "test_u_neg_24": ["[%25u]", 2147483647],
	# "test_u_neg_25": ["[%025u]", 2147483647],
    # "test_u_pos_01": ["[%0u]", 2147483647],
	# "test_u_pos_02": ["[%0.0u]", 2147483647],
	# "test_u_pos_03": ["[%.0u]", 2147483647],
	# "test_u_pos_04": ["[%25u]", 2147483647],
	# "test_u_pos_05": ["[%025.0u]", 2147483647],
	# "test_u_pos_06": ["[%25.0u]", 2147483647],
	# "test_u_pos_07": ["[%-25.0u]", 2147483647],
    # "test_u_pos_08": ["[%-5.0u]", 2147483647],
	# "test_u_pos_09": ["[%.5u]", 2147483647],
	# "test_u_pos_10": ["[%-5.5u]", 2147483647],
	# "test_u_pos_11": ["[%0.25u]", 2147483647],
	# "test_u_pos_12": ["[%.25u]", 2147483647],
	# "test_u_pos_13": ["[%-5.25u]", 2147483647],
	# "test_u_pos_14": ["[%025.25u]", 2147483647],
    # "test_u_pos_15": ["[%25.25u]", 2147483647],
	# "test_u_pos_16": ["[%-25.25u]", 2147483647],
	# "test_u_pos_17": ["[%5u]", 2147483647],
	# "test_u_pos_18": ["[%05.0u]", 2147483647],
	# "test_u_pos_19": ["[%5.0u]", 2147483647],
	# "test_u_pos_20": ["[%05.5u]", 2147483647],
	# "test_u_pos_22": ["[%5.5u]", 2147483647],
	# "test_u_pos_23": ["[%.25u]", 2147483647],
	# "test_u_pos_24": ["[%25u]", 2147483647],
	# "test_u_pos_25": ["[%025u]", 2147483647],
	# "test_x_neg_01": ["[%0x]", -2147483647],
	# "test_x_neg_02": ["[%0.0x]", -2147483647],
	# "test_x_neg_03": ["[%.0x]", -2147483647],
	# "test_x_neg_04": ["[%25x]", -2147483647],
	# "test_x_neg_05": ["[%025.0x]", -2147483647],
	# "test_x_neg_06": ["[%25.0x]", -2147483647],
	# "test_x_neg_07": ["[%-25.0x]", -2147483647],
    # "test_x_neg_08": ["[%-5.0x]", -2147483647],
	# "test_x_neg_09": ["[%.5x]", -2147483647],
	# "test_x_neg_10": ["[%-5.5x]", -2147483647],
	# "test_x_neg_11": ["[%0.25x]", -2147483647],
	# "test_x_neg_12": ["[%.25x]", -2147483647],
	# "test_x_neg_13": ["[%-5.25x]", -2147483647],
	# "test_x_neg_14": ["[%025.25x]", -2147483647],
    # "test_x_neg_15": ["[%25.25x]", -2147483647],
	# "test_x_neg_16": ["[%-25.25x]", -2147483647],
	# "test_x_neg_17": ["[%5x]", -2147483647],
	# "test_x_neg_18": ["[%05.0x]", -2147483647],
	# "test_x_neg_19": ["[%5.0x]", -2147483647],
	# "test_x_neg_20": ["[%05.5x]", -2147483647],
	# "test_x_neg_22": ["[%5.5x]", -2147483647],
	# "test_x_neg_23": ["[%.25x]", -2147483647],
	# "test_x_neg_24": ["[%25u]", -2147483647],
	# "test_x_neg_25": ["[%025x]", -2147483647],
    # "test_x_pos_01": ["[%0x]", 2147483647],
	# "test_x_pos_02": ["[%0.0x]", 2147483647],
	# "test_x_pos_03": ["[%.0x]", 2147483647],
	# "test_x_pos_04": ["[%25x]", 2147483647],
	# "test_x_pos_05": ["[%025.0x]", 2147483647],
	# "test_x_pos_06": ["[%25.0x]", 2147483647],
	# "test_x_pos_07": ["[%-25.0x]", 2147483647],
    # "test_x_pos_08": ["[%-5.0x]", 2147483647],
	# "test_x_pos_09": ["[%.5x]", 2147483647],
	# "test_x_pos_10": ["[%-5.5x]", 2147483647],
	# "test_x_pos_11": ["[%0.25x]", 2147483647],
	# "test_x_pos_12": ["[%.25x]", 2147483647],
	# "test_x_pos_13": ["[%-5.25x]", 2147483647],
	# "test_x_pos_14": ["[%025.25x]", 2147483647],
    # "test_x_pos_15": ["[%25.25x]", 2147483647],
	# "test_x_pos_16": ["[%-25.25x]", 2147483647],
	# "test_x_pos_17": ["[%5x]", 2147483647],
	# "test_x_pos_18": ["[%05.0x]", 2147483647],
	# "test_x_pos_19": ["[%5.0x]", 2147483647],
	# "test_x_pos_20": ["[%05.5x]", 2147483647],
	# "test_x_pos_22": ["[%5.5x]", 2147483647],
	# "test_x_pos_23": ["[%.25x]", 2147483647],
	# "test_x_pos_24": ["[%25x]", 2147483647],
	# "test_x_pos_25": ["[%025x]", 2147483647],
	# "test_char_c_01": ["[%c]", 'c'],
	# "test_char_c_02": ["[%-10c]", 'c'],
	# "test_char_c_03": ["[%-1c]", 'c'],
	# "test_char_c_04": ["[%10c]", 'c'],
	# "test_char_c_05": ["[%1c]", 'c'],
	# "test_char_c_06": ["[%-4c]", 'c'],
	# "test_string_01": ["[%s]", "qwerty"],
	# "test_string_01": ["[%s]", "qwerty"],
	# "test_string_02": ["[%-10s]", "qwerty"],
	# "test_string_03": ["[%10s]", "qwerty"],
	# "test_string_04": ["[%-4s]", "qwerty"],
	# "test_string_05": ["[%4s]", "qwerty"],
	# "test_string_06": ["[%-10.4s]", "qwerty"],
	# "test_string_07": ["[%10.4s]", "qwerty"],
	# "test_string_08": ["[%-4.10s]", "qwerty"],
	# "test_string_09": ["[%4.10s]", "qwerty"],
	# "test_string_10": ["[%.4s]", "qwerty"],
	# "test_string_11": ["[%1.4s]", "qwerty"],
	# "test_string_12": ["[%4.1s]", "qwerty"],
	# "test_string_13": ["[%.0s]", "qwerty"],
	# "test_string_14": ["[%4.0s]", "qwerty"],
	# "test_string_15": ["[%10.0s]", "qwerty"],
	# "test_string_16": ["[%25s]", "qwerty"],
	# "test_percent_01": ["[%0%]"],
	# "test_percent_02": ["[%0.0%]"],
	# "test_percent_03": ["[%.0%]"],
	# "test_percent_04": ["[%25%]"],
	# "test_percent_05": ["[%025.0%]"],
	# "test_percent_06": ["[%25.0%]"],
	# "test_percent_07": ["[%-25.0%]"],
    # "test_percent_08": ["[%-5.0%]"],
	# "test_percent_09": ["[%.5%]"],
	# "test_percent_10": ["[%-5.5%]"],
	# "test_percent_11": ["[%0.25%]"],
	# "test_percent_12": ["[%.25%]"],
	# "test_percent_13": ["[%-5.25%]"],
	# "test_percent_14": ["[%025.25%]"],
    # "test_percent_15": ["[%25.25%]"],
	# "test_percent_16": ["[%-25.25%]"],
	# "test_percent_17": ["[%5%]"],
	# "test_percent_18": ["[%05.0%]"],
	# "test_percent_19": ["[%5.0%]"],
	# "test_percent_20": ["[%05.5%]"],
	# "test_percent_21": ["[%5.5%]"],
	# "test_percent_22": ["[%.25%]"],
	# "test_percent_23": ["[%-025.25%]"],
	# "test_percent_24": ["[%%]"],
	# "test_percent_25": ["[%25%]"],
	# "test_percent_26": ["[%025%]"],
	# "test_all_mixeu_01": ["[%25%], [%-12u], [%12.5s], [%-4c], [%21.6d], [%0u], [%-5d]", 12, "qwerty", 'X', 12, 45678965, -6],
	"test_all_mixed_02": ["[%12.*s], [%-4c], [%21.6d], [%0u], [%-5d], [%-*x]", 3, "qwerty", 'X', 12, 45678965, -6, 14, 456],
}






MAIN_FILE = """
#include "ft_printf.h"

int main()
{{
    ft_printf({});
}}
"""

MAIN_TEMOIN = """
#include <stdio.h>

int main()
{{
    printf({});
}}
"""



def c_repr(vrepr):
    # attention les char* de len un seront des char.
    if isinstance(vrepr, str) and len(vrepr) > 1:
        return '"{}"'.format(vrepr)
    return repr(vrepr)


def all_repr(to_repr):
    return " ".join([repr(x) for x in to_repr])


def get_printf_args(list_arg):
    return ', '.join([c_repr(x) for x in list_arg])


def create_main(filename, printf_args):
    temoin = filename + '_temoin.c'
    filename += '.c'
    content = MAIN_FILE.format(printf_args)
    # print(content)
    with open(filename, 'w+') as stream:
        stream.write(content)
        stream.close()
    content = MAIN_TEMOIN.format(printf_args)
    with open(temoin, 'w+') as stream:
        stream.write(content)
        stream.close()
    return filename, temoin


def compile_main(filename, printf_args):
    filenamec, temoin = create_main(filename, printf_args)
    # faut pas hésiter à ajouter vos lib et vos header et vos sources ...
    ret = os.system(
        "gcc {filename} -g -fsanitize=address srcs/*/*.o srcs/*.o -Iincludes libft/libft.a -o {out}".format(filename=filenamec, out=filename))
    ret += os.system(
        "gcc {filename} -g -fsanitize=address srcs/*/*.o srcs/*.o -Iincludes libft/libft.a -o {out}".format(filename=temoin, out=filename + '_temoin'))
    if ret:
        print("Error: compilation on file {}".format(filename))


def compare(exec, repr_args):
    os.system("./{} > one; ".format(exec))
    os.system("./{} > two;".format(exec + '_temoin'))
    os.system("diff one two > {}.test".format(exec))
    diff = open("one").read() == open("two").read()
    os.system("rm one two")
    if not diff:
        print("\x1b[31mUnit Error [FAIL]: {} \033[0;37m".format(exec))
        os.system("cat {}.test".format(exec))
        print("")
    else:
        print("\x1b[32mPassed Test [OK]: {} \033[0;37m".format(exec))
        os.system("rm {exec}_temoin {exec} {exec}.test {exec}.c {exec}_temoin.c 2>&-".format(exec=exec))


def unit_test(dict_test):
    for key in dict_test:
        value = get_printf_args(dict_test[key])
        compile_main(key, value)
        compare(key, all_repr(dict_test[key]))


def main():
    if len(sys.argv) > 1:
        input_test = {"input_test": sys.argv[1:]}
        unit_test(input_test)
    else:
        unit_test(UNITTEST)


if __name__ == '__main__':
    main()
