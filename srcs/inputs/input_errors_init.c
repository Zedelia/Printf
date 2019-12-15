/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_errors_init.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:20 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	get_errors(t_input *l_input)
{
	size_t 				index;
	t_get_error_fct		*fonc;

	index = 0;
	while (index != errors_size)
	{
		fonc = g_get_error_fct[index];
		if (fonc(l_input) == False)
			return (false_ret(__func__));
		index++;
	}
	return (True);
}

void 	init_error_fct_tab(void)
{
	g_get_error_fct[_several_flags] = error_several_flags;
	g_get_error_fct[_too_many_stars] = error_too_many_stars;
	g_get_error_fct[_zero_sc] = error_zero_sc;
	g_get_error_fct[_preci_cp] = error_preci_cp;
	g_get_error_fct[_digit_stars_before_flag] = error_digit_stars_before_flag;
	g_get_error_fct[_digit_stars_together] = error_digit_stars_together;
	g_get_error_fct[_zeroflag_cp] = error_zeroflag_cp;
}
