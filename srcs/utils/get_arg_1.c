/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 20:43:30 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	*get_di(va_list params)
{
    int		*p_int;
	int 	var;

	var = va_arg(params, int);
    if (!(p_int = malloc(sizeof(int))))
		return (NULL);
    *p_int = var;
	return ((void *)p_int);
}

void 	*get_u(va_list params)
{
	unsigned int	*p_int;
	unsigned int 	var;

	var = va_arg(params, unsigned int);
    if (!(p_int = malloc(sizeof(unsigned int))))
		return (NULL);
    *p_int = var;
	return ((void *)p_int);
}

void 	*get_x(va_list params)
{
	char		*p_x;
	char 		*var;

	var = ft_ltoabase(va_arg(params, unsigned long long), "0123456789abcdef");
	if (!(p_x = ft_strdup(var)))
		return (NULL);
	return ((void *)p_x);
}

void 	*get_percent(va_list params)
{
	char		*p_percent;
	(void)params;

	if (!(p_percent = malloc(sizeof(char))))
		return (NULL);
	*p_percent = '%';
	return ((void *)p_percent);
}
