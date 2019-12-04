#!/usr/bin/env python3

import os
import sys

UNITTEST = {
    # nom du fichier : [format , value1, value2, ... ],
    "simple_test": ["simple"],
	#veut pas faire ces tests ???
    # "int_test_po": ["[%-10d] - [%.10d] [%-10.5d] [%-10.15d] [%010d] [%010.5d] [%010.15d]",
	# 		12, 12, 12, 12, 12, 12, 12],
    "int_test_negatif": ["[%-10d] - [%.10d] [%-10.5d] [%-10.15d] [%010d] [%010.5d] [%010.15d]",
			-12, -12, -12, -12, -12, -12, -12],
    "Unsigned_int_test": ["[%-10x] - [%.10x] [%-10.5x] [%-10.15x] [%010x] [%010.5x] [%010.15x]",
			200, 200, 200, 200, 200, 200, 200],
    # "string_test": ["0.[%s] 1.[%-10s] 2.[%10s] 3.[%-4s] 4.[%4s] 5.[%-10.4s] 6.[%10.4s] 7.[%-4.10s] 8.[%4.10s] 9.[%.4s] 1.[%1.4s] 2.[%4.1s]",
	# 		"12345","12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345"]
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
    if not diff:
        print("\x1b[31mUnit Error [FAIL]: {} \033[0;37m".format(exec))
        os.system("cat one && cat two".format(exec))
        print("")
    else:
        print("\x1b[32mPassed Test [OK]: {} \033[0;37m".format(exec))
        os.system("rm {exec} {exec}.test {exec}.c 2>&-".format(exec=exec))
    os.system("rm one two")

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
