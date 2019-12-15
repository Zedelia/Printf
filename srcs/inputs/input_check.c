/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:46 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_check(t_input *l_input)
{
	if (!(get_indicator(l_input)))
		return (false_ret(__func__));
	init_error_fct_tab();
	if (!(get_errors(l_input)))
		return (false_ret(__func__));
	return (True);
}
