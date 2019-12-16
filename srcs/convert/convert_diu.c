/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_diu.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:54 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_di(t_input *l_input)
{
	if (*((int *)l_input->varg) == 0 && (l_input->l_flag->preci)
			&& *(int *)(l_input->l_flag->preci) == 0)
	{
			if (!(apply_diux_arg_zero(l_input)))
				return (false_ret(__func__));
		return (True);
	}
	l_input->output = ft_itoa(*((int *)l_input->varg));
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_diux(l_input)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_u(t_input *l_input)
{
	int temp;

	if (*((int *)l_input->varg) == 0 && (l_input->l_flag->preci)
			&& *(int *)(l_input->l_flag->preci) == 0)
	{
		if (!(apply_diux_arg_zero(l_input)))
			return (false_ret(__func__));
		return (True);
	}
	temp = *((unsigned int *)l_input->varg);
	l_input->output = ft_utoa(temp);
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_diux(l_input)))
		return (false_ret(__func__));
	return (True);
}
