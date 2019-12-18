/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:36:04 by lolopez      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:37:38 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int		main()
{
	int a;
	int b;
	int c = 0;


	a = printf("%s\n%c\n%d\n%i\n%x\n%X\n%p\n%u\n%%\n", "jean-pierre", c, c, c, 123456, 123456, &c, 123456);
	b = ft_printf("%s\n%c\n%d\n%i\n%x\n%X\n%p\n%u\n%%\n", "jean-pierre", c, c, c, 123456, 123456, &c, 123456);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);
	c = INT_MIN;
	a = printf("%s\n%d\n%i\n%x\n%X\n%p\n%u\n%%\n", "jean-pierre",  c, c, 123456, 123456, (void *)INT_MIN, 123456);
	b = ft_printf("%s\n%d\n%i\n%x\n%X\n%p\n%u\n%%\n", "jean-pierre", c, c, 123456, 123456, (void *)INT_MIN, 123456);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test 01.10x|\n");
	a = printf("|%01.10x|\n", -1);
	b = ft_printf("|%01.10x|\n", -1);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);
printf("test 0*.*i\n");
	a = printf("|%0*.*i|\n", -5, 0, 0);
	b = ft_printf("|%0*.*i|\n", -5, 0, 0);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test 0-*pc\n");
	a = printf("|%0-*%|\n", -5);
	b = ft_printf("|%0-*%|\n", -5);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test -0*pc\n");
	a = printf("|%-0*%|\n", 5);
	b = ft_printf("|%-0*%|\n", 5);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);

	printf("test -*.*s\n");
	a = printf("|%-*.*s|\n", 5 ,2 ,NULL);
	b = ft_printf("|%-*.*s|\n", 5, 2, NULL);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test .p\n");
	a = printf("|%.p|\n", NULL);
	b = ft_printf("|%.p|\n", NULL);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
		
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test .p\n");
	a = printf("|%.p|\n", NULL);
	b = ft_printf("|%.p|\n", NULL);
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
		
	printf("printf = %d, moi = %d\n\n", a, b);

printf("test .c\n");
	a = printf("|%.c|\n", '\0');
	b = ft_printf("|%.c|\n", '\0');
	if ((a) == (b))
		puts("OK\n");
	else
		puts("FAUX\n");
		
	printf("printf = %d, moi = %d\n\n", a, b);

}
