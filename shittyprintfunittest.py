#!/usr/bin/env python3

import os
import sys

UNITTEST = {
    # nom du fichier : [format , value1, value2, ... ],
     "simple_test": ["simple"],
    "int_zero_test": ["[%0d] [%0.0d] [%.0d] [%-10d] [%.10d] [%-10.5d] [%-10.15d] [%010d] [%010.5d] [%010.15d]",
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    "int_test": ["[%0d] [%0.0d] [%.0d] [%-10d] [%.10d] [%-10.5d] [%-10.15d] [%010d] [%010.5d] [%010.15d]",
		 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647],
    "int_large_pos_test": ["[%30d] [%30.0d] [%.0d] [%-30d] [%.30d] [%-30.5d] [%-10.30d] [%030d] [%030.5d] [%010.35d]",
		 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647],
    "int_large_neg_test": ["[%30d] [%30.0d] [%.0d] [%-30d] [%.30d] [%-30.5d] [%-10.30d] [%030d] [%030.5d] [%010.35d]",
		 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
    "int_neg_test": ["[%0d] [%0.0d] [%.0d] [%-10d] [%.10d] [%-10.5d] [%-10.15d] [%010d] [%010.5d] [%010.15d]",
		 -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647],
	"u_int_test": ["[%.0u] [%-10u] [%.10u] [%-10.5u] [%-10.15u] [%010u] [%010.5u] [%010.15u]", 0, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647],
	"u_int_neg_test": ["[%.0u] [%-10u] [%.10u] [%-10.5u] [%-10.15u] [%010u] [%010.5u] [%010.15u]", -12, -12, -12, -12, -12, -12, -12, -12],
    "string_test": ["%s %s", "qwerty", "coucou"]
}


MAIN_FILE = """
#include "ft_printf.h" // la normalement tu mets #include "ft_printf.h"

int main()
{{
    ft_printf({}); // faut mettre votre ft_printf
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
    filename += '.c'
    content = MAIN_FILE.format(printf_args)
    # print(content)
    with open(filename, 'w+') as stream:
        stream.write(content)
        stream.close()
    return filename


def compile_main(filename, printf_args):
    filenamec = create_main(filename, printf_args)
    # faut pas hésiter à ajouter vos lib et vos header et vos sources ...
    ret = os.system(
        "gcc {filename} -g -fsanitize=address srcs/*/*.c srcs/*.c -Iincludes libft/libft.a -o {out}".format(filename=filenamec, out=filename))
    if ret:
        print("Error: compilation on file {}".format(filename))


def compare(exec, repr_args):
    os.system("./{} > one; ".format(exec))
    os.system("printf {} > two;".format(repr_args))
    os.system("diff one two > {}.test".format(exec))
    diff = open("one").read() == open("two").read()
    os.system("rm one two")
    if not diff:
        print("\x1b[31mUnit Error [FAIL]: {} \033[0;37m".format(exec))
        os.system("cat {}.test".format(exec))
        print("")
    else:
        print("\x1b[32mPassed Test [OK]: {} \033[0;37m".format(exec))
        os.system("rm {exec} {exec}.test {exec}.c 2>&-".format(exec=exec))


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
