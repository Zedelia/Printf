/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 21:24:04 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	*get_di(va_list params)
{
    int		*p_int;
	int 	value;

	value = va_arg(params, int);
    if (!(p_int = malloc(sizeof(int))))
		return (NULL);
    *p_int = value;
	return ((void *)p_int);
}

void 	*get_u(va_list params)
{
	unsigned int	*p_int;
	unsigned int 	value;

	value = va_arg(params, unsigned int);
    if (!(p_int = malloc(sizeof(unsigned int))))
		return (NULL);
    *p_int = value;
	return ((void *)p_int);
}

void 	*get_x(va_list params)
{
	char		*p_x;
	t_uintmax value;

	value = va_arg(params, t_uintmax);
	if(!(p_x = ft_ltoabase(value, "0123456789abcdef")))
		return (NULL);
	return ((void *)p_x);
}

void 	*get_p(va_list params)
{
	t_uintmax	value;
	char		*value_str;
	char		*p_p;
	char		*fill_char;

	value = va_arg(params, t_uintmax);
	if (!(value_str = ft_ltoabase(value, "0123456789abcdef")))
		return (NULL);
	fill_char = "0x";
	if (!(p_p = ft_strjoin(p_p, value_str)))
		return (NULL);
	ft_memdel((void **)value_str);
	return ((void *)p_p);

}
