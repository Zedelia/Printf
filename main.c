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
		char* c = va_arg(parameters, char*);
		printf(">> %s\n----------\n", c);
		i++;
	}
	return (0);
}




int main(int argc, char** argv)
{
	test_char(argc - 1, argv[1], argv[2], argv[3], argv[4]);
	printf("> %d", ft_atoi("12"));

	return (0);
}