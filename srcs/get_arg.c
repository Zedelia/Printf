/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 12:13:52 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 18:06:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	*get_di(va_list params)
{
    int		*p_int;
	int 	var;

	var = va_arg(params, int);
    if (!(p_int = malloc(sizeof(int))))
		return (False);
    *p_int = var;
	return ((void *)p_int);
}



t_bool 	get_arg(t_pattern *l_pattern, va_list params)
{

	t_get_fct fonc;
	size_t 	index;

	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_get_fct[index];
	l_pattern->varg = fonc(params);
	if (!(l_pattern->varg))
		return (False);
	return (True);
}
