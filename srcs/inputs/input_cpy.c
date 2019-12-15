/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_cpy.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:07 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_cpy(t_input *l_input)
{
	size_t n;

	n = 1;
	while (is_indicator(l_input->p_input[n]) == False)
		n++;
	if (!(l_input->input_cpy = ft_strndup(&(l_input->p_input[1]), n)))
		return (false_ret(__func__));
	if (!(input_check(l_input)))
		return (false_ret(__func__));
	return (True);
}
