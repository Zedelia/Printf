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
	char a = 'd';
	char a1 = 'e';
	char a2 = 's';
	// char a3 = 'a';
	// char a4 = 'a';
	// test_char(4, a1, a2, a3, a4);
	//
	// // char *str = ft_strdup("hello c'est moi")
	// //
	// // ft_strmove(str, str + 3);
	// // // printf("%s\n", str);
	ft_printf("%c coucou %c %c \n", a, a1, a2);

	return (0);
}
