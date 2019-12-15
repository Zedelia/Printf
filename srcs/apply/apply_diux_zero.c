/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_zero.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:01:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	apply_diux_zero(t_pattern *l_pattern, char *cpy_result)
{
	if (ft_atoi(l_pattern->result) < 0 && l_pattern->indicator != 'u')
	{
		if (!(apply_diux_zero_neg(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux_zero_pos(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	return (True);
}
