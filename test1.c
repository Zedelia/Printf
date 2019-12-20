#include "includes/ft_printf.h"


// ------------------ tests va_arg --------------------------
int test_int(int n, ...)
{
	int i = 0;
	va_list parameters;
	va_start(parameters, n);

	while (i < n)
	{
		int c = va_arg(parameters, int);
		printf(">> %d\n----------\n", c);
		i++;
	}
	return (0);
}
int test_char(int n, ...)
{
	int i = 0;
	va_list parameters;
	va_start(parameters, n);

	while (i < n)
	{
		char c = va_arg(parameters, int);
		printf(">> %c\n----------\n", c);
		i++;
	}
	return (0);
}



int main(void)
{

	char *p = NULL;

	ft_printf("1. |%.*s|\n", 5, "bonjour");
	printf("1. |%.*s|\n", 5, "bonjour");


	return (0);
}
