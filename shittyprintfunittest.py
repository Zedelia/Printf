#!/usr/bin/env python3

import os
import sys

UNITTEST = {
    # nom du fichier : [format , value1, value2, ... ],
     "simple_test": ["simple"],
    "int_zero_01": ["[%0d]", 0],
	"int_zero_02": ["[%0.0d]", 0],

	#  [%.0d] [%15d] [%015.0d] [%15.0d] [%-15.0d] [%5d] [%05.0d] [%5.0d] [%-5.0d] [%05.5d] [%.5d] [%-5.5d] [%5.5d] [%0.15d] [%.15d] [%-5.15d] [%015.15d] [%15.15d] [%-15.15d] [%015.15d] [%.15d] [%-15.15d]",
	# 	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    # "int_pos_test": ["[%0d] [%0.0d] [%.0d] [%30d] [%030.0d] [%30.0d] [%-30.0d] [%5d] [%05.0d] [%5.0d] [%-5.0d] [%05.5d] [%.5d] [%-5.5d] [%5.5d] [%0.15d] [%.15d] [%-5.15d] [%015.15d] [%15.15d] [%-15.15d] [%015.15d] [%.15d] [%-15.15d]",
	# 	 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
    # "int_neg_test": ["[%0d] [%0.0d] [%.0d] [%15d] [%015.0d] [%15.0d] [%-15.0d] [%5d] [%05.0d] [%5.0d] [%-5.0d] [%05.5d] [%.5d] [%-5.5d] [%5.5d] [%0.15d] [%.15d] [%-5.15d] [%015.15d] [%15.15d] [%-15.15d] [%015.15d] [%.15d] [%-15.15d]",
 	# 	 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
	# "u_ pos_int_test": ["[%0u] [%0.0u] [%.0u] [%30u] [%030.0u] [%30.0u] [%-30.0u] [%5u] [%05.0u] [%5.0u] [%-5.0u] [%05.5u] [%.5u] [%-5.5u] [%5.5u] [%0.15u] [%.15u] [%-5.15u] [%015.15u] [%15.15u] [%-15.15u] [%015.15u] [%.15u] [%-15.15u]",
	# 	 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
	"u_neg_int_test":["[%0u] [%0.0u] [%.0u] [%30u] [%030.0u] [%30.0u] [%-30.0u] [%5u] [%05.0u] [%5.0u] [%-5.0u] [%05.5u] [%.5u] [%-5.5u] [%5.5u] [%0.15u] [%.15u] [%-5.15u] [%015.15u] [%15.15u] [%-15.15u] [%015.15u] [%.15u] [%-15.15u]",
		 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
    "string_test": ["[%s] [%.0s] [%3s] [%30s] [%.3s] [%.30s] [%3.3s] [%30.3s] [%3.30s] [%30.30s]", "qwerty", "coucou"],
	"string_test": ["%s %s", "qwerty", "coucou"]
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
        "gcc {filename} -g -fsanitize=address srcs/*/*.c srcs/*.c -Iincludes libft/libft.a -o {out}".format(filename=filenamec, out=filename))
    ret += os.system(
        "gcc {filename} -g -fsanitize=address srcs/*/*.c srcs/*.c -Iincludes libft/libft.a -o {out}".format(filename=temoin, out=filename + '_temoin'))
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
