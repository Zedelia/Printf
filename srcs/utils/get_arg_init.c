/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 18:32:02 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	init_get_fct_tab(void)
{
	g_get_fct[_c] = get_c;
	g_get_fct[_s] = get_s;
	g_get_fct[_p] = get_p;
	g_get_fct[_d] = get_di;
	g_get_fct[_i] = get_di;
	g_get_fct[_u] = get_u;
	g_get_fct[_x] = get_x;
	g_get_fct[_big_x] = get_x;
	g_get_fct[_percent] = get_percent;
}

t_bool 	get_arg(t_pattern *l_pattern, va_list params)
{
	t_get_fct 	*fonc;
	size_t 		index;

	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_get_fct[index];
	l_pattern->varg = fonc(params);
	if (!(l_pattern->varg))
		return (false_ret(__func__));
	return (True);
}
