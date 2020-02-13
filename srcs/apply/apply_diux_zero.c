/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_zero.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:43:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	apply_diux_zero(t_input *l_input, char *cpy_output)
{
	if (ft_atoi(l_input->output) < 0 && l_input->indicator != 'u')
	{
		if (!(apply_diux_zero_neg(l_input, cpy_output)))
			return (false_ret(__func__));;
	}
	else
	{
		if (!(apply_diux_zero_pos(l_input, cpy_output)))
			return (false_ret(__func__));;
	}
	return (True);
}
