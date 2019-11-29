/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_width.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:21:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 18:35:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool		flag_width(t_flag **l_flag, char *flags, va_list params)
{
	size_t 	i;
	char 	*temp;
	int  	*p_int;

	i = 0;
	if (flags[0] == '*')
	{
		if (!((*l_flag)->width = get_di(params)))
			return (False);
		return (True);
	}
	while (ft_isdigit(flags[i]) == True)
		i++;
	if (i == 0 && flags[0] != '*')
		return (False);
	if (!(temp = ft_strndup((const char*)&flags[0], i)))
		return (False);
	if (!(p_int = malloc(sizeof(int))))
			return (False);
	*p_int = ft_atoi(temp);
	(*l_flag)->width = (void*)(p_int);
	return (True);
}
