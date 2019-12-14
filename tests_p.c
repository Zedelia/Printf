#include "includes/ft_printf.h"



int main(void)
{
	// TEST INT


	printf("\n[%4p]\n", "lol");
	ft_printf("[%4p]\n", "lol");

	printf("\n--------------\n");

	printf("\n[%p]\n", "lol");
	ft_printf("[%p]\n", "lol");

	printf("\n--------------\n");

	printf("\n[%-20p]\n", "lol");
	ft_printf("[%-20p]\n", "lol");

	printf("\n--------------\n");

	printf("\n[%-1p]\n", "lol");
	ft_printf("[%-1p]\n", "lol");

	printf("\n--------------\n");

	printf("\n[%20p]\n", "lol");
	ft_printf("[%20p]\n", "lol");

	printf("\n--------------\n");

	printf("\n[%1p]\n", "lol");
	ft_printf("[%1p]\n", "lol");

		"test_string_16": ["[%s]", NULL],

	return (0);
}
