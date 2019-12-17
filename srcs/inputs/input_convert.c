/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_convert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 09:36:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 09:53:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool 	input_convert(t_input *l_input)
{
	if (!input_convert_init(l_input))
		return (false_ret(__func__));
		// prevoir si le indicator = c et output == 0 => memjoin ici
	if (!(l_input->p_input = ft_strjoin((const char*)l_input->output,
			l_input->p_input + l_input->len)))
		return (false_ret(__func__));
	return (True);
}
