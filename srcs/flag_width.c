/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_width.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:21:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 12:35:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool		flag_width(t_flag *l_flag, char *flags, va_list params)
{
	size_t 	i;
	char 	*temp;
	int  	*p_int;

	i = 0;
	if (flags[0] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (false_ret(__func__));
		return (True);
	}
	while (ft_isdigit(flags[i]) == True)
		i++;
	if (!(temp = ft_strndup((const char*)&flags[0], i)))
		return (false_ret(__func__));

	if (!(p_int = malloc(sizeof(int))))
			return (false_ret(__func__));
	*p_int = ft_atoi(temp);
	l_flag->width = (void*)(p_int);
	return (True);
}
