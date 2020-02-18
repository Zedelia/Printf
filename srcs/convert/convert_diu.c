/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:01 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_di(t_input *l_input)
{
	if ((l_input->l_flag) && *((int *)l_input->varg) == 0
		&& (l_input->l_flag->preci)
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

t_bool	convert_u(t_input *l_input)
{
	int temp;

	if ((l_input->l_flag) && *((int *)l_input->varg) == 0
		&& (l_input->l_flag->preci)
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
