/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_convert_init.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 19:59:10 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:49:26 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	init_convert_fct_tab(void)
{
	g_convert_fct[_c] = convert_c;
	g_convert_fct[_s] = convert_s;
	g_convert_fct[_p] = convert_p;
	g_convert_fct[_d] = convert_di;
	g_convert_fct[_i] = convert_di;
	g_convert_fct[_u] = convert_u;
	g_convert_fct[_x] = convert_di;
	g_convert_fct[_big_x] = convert_x;
	g_convert_fct[_percent] = convert_percent;
}

t_bool 	pattern_convert(t_pattern *l_pattern)
{
	t_convert_fct 	*fonc;
	size_t 			index;

	init_convert_fct_tab();
	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_convert_fct[index];
	if (!(fonc(l_pattern)))
		return (false_ret(__func__));
	if (!(l_pattern->p_pattern = ft_strjoin((const char*)l_pattern->result,
			l_pattern->p_pattern + l_pattern->len)))
		return (false_ret(__func__));
	return (True);
}
