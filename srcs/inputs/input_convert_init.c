/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_convert_init.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:06 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:02:14 by mbos        ###    #+. /#+    ###.fr     */
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
	g_convert_fct[_x] = convert_x;
	g_convert_fct[_big_x] = convert_x;
	g_convert_fct[_percent] = convert_percent;
}

t_bool 	input_convert(t_input *l_input)
{
	t_convert_fct 	*fonc;
	size_t 			index;

	init_convert_fct_tab();
	index = ft_index(l_input->indicator, INDICATORS);
	fonc = g_convert_fct[index];
	if (!(fonc(l_input)))
		return (false_ret(__func__));
	if (!(l_input->p_input = ft_strjoin((const char*)l_input->output,
			l_input->p_input + l_input->len)))
		return (false_ret(__func__));
	return (True);
}
