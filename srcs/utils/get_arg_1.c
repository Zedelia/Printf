/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 09:23:49 by mbos        ###    #+. /#+    ###.fr     */
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

	value = va_arg(params, unsigned int);
	if(!(p_x = ft_ltoabase(value, "0123456789abcdef")))
		return (NULL);
	return ((void *)p_x);
}

void 	*get_big_x(va_list params)
{
	char		*p_x;
	t_uintmax 	value;
	int 		i;

	value = va_arg(params, unsigned int);
	if(!(p_x = ft_ltoabase(value, "0123456789abcdef")))
		return (NULL);
	i = 0;
	while (p_x[i])
	{
		if (ft_isalpha(p_x[i]) == 1)
			p_x[i] -= 32;
		i++;
	}
	return ((void *)p_x);
}

void 	*get_p(va_list params)
{
	void	*value;
	char	*p_p;
	char	*fill_char;

	if (!(value = va_arg(params, void*)))
	{
		if(!(p_p = ft_strdup("0x0")))
			return (NULL);
		return ((void *)p_p);
	}
	if (!(p_p = ft_ltoabase((unsigned long)value, "0123456789abcdef")))
		return (NULL);
	fill_char = "0x";
	if (!(p_p = ft_strjoin(fill_char, p_p)))
		return (NULL);
	return ((void *)p_p);
}
