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
	// char a = 'd';
	// char a1 = 'e';
	// char a2 = 's';
	ft_printf("hello hey %-10d   \n", 11);
	printf("\n>> .%-10d.", 11);
	printf("\n>> .%-5.4d.", 11);
	// printf("%-2.d\n", 14);

	return (0);
}
