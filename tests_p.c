#include "includes/ft_printf.h"



int main(void)
{
	// TEST INT
	char *test = NULL;

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

	printf("\n--------------\n");

	printf("\n[%*p]\n", 40, test);
	ft_printf("[%*p]\n", 40, test);

	printf("\n--------------\n");

	printf("\n[%*p]\n", -40, test);
	ft_printf("[%*p]\n", -40, test);

	printf("\n--------------\n");

	printf("\n[%*s]\n", -40, test);
	ft_printf("[%*s]\n", -40, test);

	printf("\n--------------\n");

	printf("\n[%*.2s]\n", -40, test);
	ft_printf("[%*.2s]\n", -40, test);

	printf("\n--------------\n");

	printf("\n[%*s]\n", 40, test);
	ft_printf("[%*s]\n", 40, test);

	printf("\n--------------\n");

	printf("\n[%*.2s]\n", 40, test);
	ft_printf("[%*.2s]\n", 40, test);
		// "test_string_16": ["[%s]", NULL],

	return (0);
}
