/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_apply_init.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:33:30 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 15:42:29 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	init_apply_fct_tab(void)
{
	g_apply_fct[_c] = apply_c;
	g_apply_fct[_s] = apply_s;
	g_apply_fct[_p] = apply_p;
	g_apply_fct[_d] = apply_di;
	g_apply_fct[_i] = apply_di;
	g_apply_fct[_u] = apply_u;
	g_apply_fct[_x] = apply_x;
	g_apply_fct[_big_x] = apply_x;
	g_apply_fct[_percent] = apply_percent;
}

t_bool 	pattern_apply(t_pattern *l_pattern)
{
	t_apply_fct 	*fonc;
	size_t 			index;

	init_apply_fct_tab();
	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_apply_fct[index];
	if (!(l_pattern->result = fonc(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
