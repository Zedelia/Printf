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
	// ft_putchar('\0');
	// TEST INT
	// int i;
	// int j;

	// i = ft_printf("[%1.3s], [%1.6s],\n", "qwerty",  "coucou");
	// printf("\n>> %d\n", i);
	// j = printf("[%1.3s], [%1.6s],\n", "qwerty", "coucou");
	// printf("\n>> %d\n\n", j);

	ft_printf("%% qwerty [%1.*s], [%8c], [%*.6d], [%% %u],  [%-*x], [%-8.*d],", 3, "qwerty", 'X', 5, 12, 45678965, -6, 14, 456, 45);
	// printf("\n>> %d\n", i);

	// printf("\n>> %d", j);


	// ft_printf("%-*x]\n", -6, 14);
	// printf("%-*x]", -6, 14);

	// ft_printf("%-*x]\n", -6, 14);
	// printf("%-*x]", -6, 14);

		//
		//
		// "test_string_17": ["%25.25s]", "qwerty"],
		// 	"test_string_25": ["%*.*s]", 25, -25, "qwerty"],
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

	// while (1);
	return (0);
}
