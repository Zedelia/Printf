/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:08:51 by mbos        ###    #+. /#+    ###.fr     */
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

void 	*get_c(va_list params)
{
	char		*p_c;
	char 		var;

	var = va_arg(params, int);
	if (!(p_c = malloc(sizeof(char))))
		return (NULL);
	*p_c = var;
	return ((void *)p_c);
}

void 	*get_s(va_list params)
{
	char		*p_s;
	char 		*var;

	var = va_arg(params, char*);
	if (!(p_s = ft_strdup(var)))
		return (NULL);
	return ((void *)p_s);
}

void 	*get_x(va_list params)
{
	char		*p_x;
	char 		*var;

	var = convert_base_int_to_hex(va_arg(params, int));
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
