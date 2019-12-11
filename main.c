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
	// TEST INT

	// char *s = NULL;


	// printf("[%-15%]\n");
	printf("\n[%-4.10s]\n","qwerty");

	ft_printf("[%-4.10s]", "qwerty");

	// ft_printf("\n\n[%s]\n", s);

//----------------------------------

	// TEST char
	// ft_printf("Int :\n[%c]\n[%-10c]\n[%10c]\n",
	// 		'c', 'c', 'c');
	// printf("TEMOIN :\n[%c]\n[%-10c]\n[%10c]\n",
	// 		'c', 'c','c' );
	// ft_printf("char s:\n0.[%s]\n1.[%-10s]\n2.[%10s]\n3.[%-4s]\n4.[%4s]\n5.[%-10.4s]\n6.[%10.4s]\n7.[%-4.10s]\n8.[%4.10s]\n9.[%.4s]\n1.[%1.4s]\n2.[%4.1s]\n",
	// 				"12345","12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345");
	//
	// printf("\n\nTEMOIN s:\n0.[%s]\n1.[%-10s]\n2.[%10s]\n3.[%-4s]\n4.[%4s]\n5.[%-10.4s]\n6.[%10.4s]\n7.[%-4.10s]\n8.[%4.10s]\n9.[%.4s]\n1.[%1.4s]\n2.[%4.1s]\n",
	// 		"12345","12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345", "12345");

	return (0);
}
