/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_diu.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:01:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_di(t_pattern *l_pattern)
{
	if (*((int *)l_pattern->varg) == 0 && (l_pattern->l_flag->preci)
			&& *(int *)(l_pattern->l_flag->preci) == 0)
	{
			if (!(apply_diux_arg_zero(l_pattern)))
				return (false_ret(__func__));
		return (True);
	}
	l_pattern->result = ft_itoa(*((int *)l_pattern->varg));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_diux(l_pattern)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_u(t_pattern *l_pattern)
{
	int temp;

	if (*((int *)l_pattern->varg) == 0 && (l_pattern->l_flag->preci)
			&& *(int *)(l_pattern->l_flag->preci) == 0)
	{
		if (!(apply_diux_arg_zero(l_pattern)))
			return (false_ret(__func__));
		return (True);
	}
	temp = *((unsigned int *)l_pattern->varg);
	l_pattern->result = ft_utoa(temp);
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_diux(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
