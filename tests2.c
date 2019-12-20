#include "includes/ft_printf.h"



int main(void)
{
	// TEST INT
	char *test = NULL;

	printf("\n%*.*s]\n", 25, -25, "lol");
	ft_printf("%*.*s]\n", 25, - 25, "lol");


		// "test_string_16": ["%s]", NULL],

	return (0);
}
